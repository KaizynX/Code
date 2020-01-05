#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const int M = 3e5+7;

int n, m;
int vis[N];
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
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in[i].size() && ot[i].size())
            q.push(i), vis[i] = 1;
    }
    while (q.size()) {
        int cur = q.front();
        q.pop();
        vis[cur] = 0;
        auto i = in[cur].rbegin(), j = ot[cur].rbegin();
        while (i != in[cur].rend() && j != ot[cur].rend()) {
            long long mv = min(mp[{*i, cur}], mp[{cur, *j}]);
            if (*i != *j) {
                mp[{*i, *j}] += mv;
                in[*j].emplace_back(*i);
                ot[*i].emplace_back(*j);
                if (in[*i].size() && ot[*i].size() && !vis[*i]) vis[*i] = 1, q.push(*i);
                if (in[*j].size() && ot[*j].size() && !vis[*j]) vis[*j] = 1, q.push(*j);
            }
            if (!(mp[{*i, cur}] -= mv)) ++i, in[cur].pop_back();
            if (!(mp[{cur, *j}] -= mv)) ++j, ot[cur].pop_back();
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



