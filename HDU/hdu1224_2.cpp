#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T, n, m;
int a[N], dis[N], last[N];
vector<int> e[N];

inline void dijskra()
{
    typedef pair<int, int> pii;
    priority_queue<pii> q;
    q.push({0, 1});
    while (q.size()) {
        pii u = q.top();
        q.pop();
        if (u.first < dis[u.second]) continue;
        for (int v : e[u.second]) {
            int d = u.first+a[v];
            if (d <= dis[v]) continue;
            dis[v] = d;
            last[v] = u.second;
            q.push({d, v});
        }
    }
}

inline void print()
{
    vector<int> path;
    for (int i = n+1; i; i = last[i])
        path.emplace_back(i);
    reverse(path.begin(), path.end());
    for (int i = 0; i < (int)path.size()-1; ++i)
        cout << path[i] << "->";
    cout << "1\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        memset(dis, 0, sizeof dis);
        memset(last, 0, sizeof last);
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            vector<int>().swap(e[i]);
        }
        a[n+1] = 0;
        vector<int>().swap(e[n+1]);
        cin >> m;
        for (int i = 1, u, v; i <= m; ++i) {
            cin >> u >> v;
            e[u].emplace_back(v);
        }
        dijskra();
        cout << "CASE " << t << "#\n"
             << "points : " << dis[n+1] << "\n"
             << "circuit : ";
        print();
        if (t < T) cout << endl;
    }
    return 0;
}
