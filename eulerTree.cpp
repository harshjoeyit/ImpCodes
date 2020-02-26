#include<bits/stdc++.h>
using namespace std;

#define int long long int 

const int N = 10000;
vector<int> G[N];
int vis[N];
int euler[2*N];
vector<pair<int, int>> first_last(N);


void eulerTree(int u, int &indx) 
{ 
    vis[u] = 1; 
    euler[indx++] = u; 
    for(auto it : G[u]) { 
        if (!vis[it]) { 
            eulerTree(it, indx);        // calling recursive on one of the subtress of u
            euler[indx++] = u;          // after call the path comes back to the parent node so print again 
        }                               // any parent node is printed (1+number of children times) 
    } 
}	


void printeulerTour(int root, int n) 
{ 
    int index = 0;   
    eulerTree(root, index); 
    for(int i = 0; i < (2*n-1); i++) 
        cout << euler[i] << " "; 
} 
  

void calc_subtree_nodes(int n)
{

    for(int i = 1; i <= n; i++)
        first_last[i].first = first_last[i].second = -1;

    for(int i = 0; i < 2*n-1; i++)
    {
        int v = euler[i];
        if(first_last[v].first == -1)
            first_last[v].first = first_last[v].second = i;
        else
            first_last[v].second = i;
    }

    cout << endl;
    for(int i = 1; i <= n; i++)
        cout << i << "- "<< (first_last[i].second - first_last[i].first)/2 << endl;
}



signed main()
{
	int n;
	cin >> n;

	for(int i = 0; i < n-1; i++)
	{
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

    printeulerTour(1, n); 
    calc_subtree_nodes(n);
}