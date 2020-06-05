#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(n+1);

    for(int i=0; i<n; i++) {
        if(s[i] == '1') {
            v[i+1] = 1;
        } else {
            v[i+1] = -1;
        }
        v[i+1] += v[i];
    }

    map<int, pair<int, int>> mp;
    mp[0] = make_pair(0, 0);
    for(int i=1; i<=n; i++) {
        if(mp.count(v[i])) {
            mp[v[i]].second = i;
        } else {
            mp[v[i]] = make_pair(i, i);
        }
    }

    int ans = 0;
    for(auto &p: mp) {
        ans = max(ans, p.second.second - p.second.first);
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}