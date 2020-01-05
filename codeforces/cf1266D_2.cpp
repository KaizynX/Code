#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const int M = 3e5+7;

int n, m;
set<int> in[N], ot[N];
map<pair<int, int>, long long> mp;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1, u, v, d; i <= m; ++i) {
        cin >> u >> v >> d;
        if (u == v) continue;
        ot[u].insert(v);
        in[v].insert(u);
        mp[{u, v}] += d;
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in[i].size() && ot[i].size())
            q.push(i);
    }
    while (q.size()) {
        int cur = q.front();
        q.pop();
        for (int i : in[cur]) {
            for (int j : ot[cur]) {
                long long mv = min(mp[{i, cur}], mp[{cur, j}]);
                if (!(mp[{i, cur}] -= mv)) in[cur].erase(i);
                if (!(mp[{cur, j}] -= mv)) ot[cur].erase(j);
                mp[{i, j}] += mv;
                if (in[j].find(i) != in[j].end()) in[j].insert(i);
                if (ot[i].find(j) != ot[i].end()) ot[i].insert(j);
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


