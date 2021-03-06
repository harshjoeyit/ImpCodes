
// Using euler tour and segment tree(RSQ) for subtree sum of a tree
// Goal is to convert tree into a array using euler tour
// and the perform queries based on entry and exit time

#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 1e5+10;    
int n, q;                                            
vector<int> g[mxN];                                 
int vis[mxN];
int a[4*mxN];       // i is time a[i] is node 
int b[mxN];         // node value 
int ent[mxN*10];    // entry time
int ex[mxN*10];     // exit time
int ind = 0;

struct segtree {
    int *tree = new int[4*mxN];
    int *lazy = new int[4*mxN];

    void build(int *a, int i=1, int s = 0, int e = 2*n-1) {
        if(s > e)
            return;
        if(s == e) {
            // here we are quering sum of squares of node values
            tree[i] = (a[s]*a[s]);                    
            return;
        }
        int mid = (s + e)/2;
        build(a, 2*i, s, mid);
        build(a, 2*i+1, mid+1, e);
        tree[i] = tree[2*i] + tree[2*i+1];
    }
    
    void update(int l, int r, int new_val, int i = 1, int s = 0, int e =2*n-1) {
        // update tree nodes using lazy tree nodes
        if(lazy[i] != 0) {
            tree[i] += lazy[i];
            if(s != e) {                            
                // not a leaf node - propagate the update in lazy tree 
                lazy[2*i] += lazy[i];
                lazy[2*i + 1] += lazy[i];
            }
            lazy[i] = 0;
        }
        if(l > e || r < s)
            return;
        // segment fits inside current range [l, r]
        if(l <= s && e <= r) {
            // square sum query
            tree[i] = new_val * new_val;            
            if(s != e) {
                lazy[2*i] += new_val;
                lazy[2*i + 1] += new_val;
            }
            return;
        }
        int mid = (s + e)/ 2;
        update(l, r, new_val, 2*i, s, mid);
        update(l, r, new_val, 2*i + 1, mid + 1, e);
        tree[i] = tree[2*i] + tree[2*i + 1];
    }
    
    int query(int l, int r, int i=1, int s=0 , int e=2*n-1) {
        if(lazy[i] != 0) {
            tree[i] += lazy[i];
            if(s != e) {
                lazy[2*i] += lazy[i];
                lazy[2*i + 1] += lazy[i];
            }    
            lazy[i] = 0;
        }
        if(l > e || r < s)
            return 0;

        if(l <= s && e <= r)
            return tree[i];

        int mid = (s + e)/2;
        int leftans = query(l, r, 2*i, s, mid);
        int rightans = query(l, r, 2*i + 1, mid + 1, e);

        return (leftans + rightans);
    }
    
    void disp(int n) {
        for(int i = 0; i < 4*n+1; i++)
            cout << tree[i] << " ";
        cout << endl;
        for(int i = 0; i < 4*n+1; i++)
            cout << lazy[i] << " ";
        cout << endl;
    }
};


void input() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    
    int x, y;
    for(int i = 0; i < n-1; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);    
    }
}

void dfs(int u) {
    vis[u] = 1;
    // subtree start(in)
    a[ind++] = u;                   
    for(auto v: g[u]) {
        if(!vis[v]){
            dfs(v);
        }
    }
    // subtree end(out)
    a[ind++] = u;                   
}

void inout() {
    memset(ent, -1, sizeof(ent));
    for(int i = 0; i < 2*n; i++) {
        if(ent[a[i]] == -1)
            // first occurance
            ent[a[i]] = i;
        else 
            // second occurance
            ex[a[i]] = i; 
    }
}

void disp() {
    for(int i = 0; i < 2*n; i++) {
        cout << a[i] << " ";
    }   
    cout << endl;
}

void Query() {
    segtree st;
    st.build(a);
    // st.disp(2*n);
    cin >> q;
    for(int i = 0; i < q; i++) {
        int qt, v, val;
        cin >> qt >> v;
        if(qt == 2) {
            // ans is added twice so half
            cout << st.query(ent[v], ex[v]) / 2 << endl;
        } else {
            cin >> val;
            // point update 
            // we have two occurnce of node- entry and exit - so update at both places  
            st.update(ent[v], ent[v], val);
            st.update(ex[v], ex[v], val);
        }
    }
}
void solve() {
    input();
    dfs(1);
    inout();
                                    
    for(int i = 0; i < 2*n; i++) {                      
        // node number replaced by value of node 
        a[i] = b[a[i]];
    }
    Query();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}