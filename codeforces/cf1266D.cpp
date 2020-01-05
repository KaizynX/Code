#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const int M = 3e5+7;

int n, m;
vector<int> in[N], ot[N];
map<pair<int, int>, long long> mp;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1, u, v, d; i <= m; ++i) {
        cin >> u >> v >> d;
        if (u == v) continue;
        ot[u].emplace_back(v);
        in[v].emplace_back(u);
        mp[{u, v}] += d;
    }
    for (int i = 1; i <= n; ++i) {
        for (int id : in[i]) {
            for (int od : ot[i]) {
                long long mv = min(mp[{id, i}], mp[{i, od}]);
                mp[{id, i}] -= mv;
                mp[{i, od}] -= mv;
                if (id != od) mp[{id, od}] += mv;
            }
        }
    }
    int cnt = 0;
    for (auto p : mp)
        if (p.second)
            ++cnt;
    cout << cnt << endl;
    for (auto p : mp)
        if (p.second)
            cout << p.first.first << " " << p.first.second << " " << p.second << endl;
    return 0;
}

