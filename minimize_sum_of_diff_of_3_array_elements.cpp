#include <bits/stdc++.h>
using namespace std;

#define int long long
int t, nr, ng, nb;
int ans;


void solve(vector<int> a, vector<int> b, vector<int> c) {
    
    for (auto x : a) {
        auto y = lower_bound(b.begin(), b.end(), x);        // equal to greater than x
        auto z = upper_bound(c.begin(), c.end(), x);        // greater than x;
        
        if (y == b.end() || z == c.begin()) { 
            continue; 
        }
        z--; // equal to or less than x;
        // *z  <= x <= *y
        ans = min(ans, (int)(abs(x - *y) + abs(*y - *z) + abs(*z - x)));
    }
}

signed main() {
    for (cin >> t; t; t--) {
        cin >> nr >> ng >> nb;
        vector<int> r(nr), g(ng), b(nb);

        for (int i = 0; i < nr; i++) { 
            cin >> r[i]; 
        }
        for (int i = 0; i < ng; i++) { 
            cin >> g[i]; 
        }
        for (int i = 0; i < nb; i++) { 
            cin >> b[i]; 
        }
        
        sort(r.begin(), r.end());
        sort(g.begin(), g.end());
        sort(b.begin(), b.end());

        ans = 9e18;
        
        solve(r, g, b);
        
        cout << ans << endl;
    }
    return 0;
}