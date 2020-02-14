#include <bits/stdc++.h>

using namespace std;

const int N = 5e2+7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m, s, t;
int dis[N], path[N];
vector<pii> ed[N], et[N];

inline void dijskra(vector<pii> e[])
{
    memset(dis, 0x3f, sizeof dis);
    memset(path, -1, sizeof path);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, t});
    dis[t] = 0;
    while (q.size()) {
        pii u = q.top();
        q.pop();
        if (u.first > dis[u.second]) continue;
        if (u.second == s) break;
        for (pii v : e[u.second]) {
            int tmp = v.first+u.first;
            if (tmp >= dis[v.second]) continue;
            dis[v.second] = tmp;
            path[v.second] = u.second;
            q.push({tmp, v.second});
        }
    }
}

inline void print()
{
    cout << " = " << dis[s] << ": ";
    for (int i = s; i != t; i = path[i])
        cout << i << " => ";
    cout << t << endl;
}

int main()
{
    cin >> n >> m;
    for (int i = 1, u, v, d, t, one; i <= m; ++i) {
        cin >> u >> v >> one >> d >> t;
        // reverse the map
        swap(u, v);
        ed[u].emplace_back(d, v);
        et[u].emplace_back(t, v);
        if (one) continue;
        ed[v].emplace_back(d, u);
        et[v].emplace_back(t, u);
    }
    cin >> s >> t;
    dijskra(et);
    cout << "Time";
    print();
    dijskra(ed);
    cout << "Distance";
    print();
    return 0;
}
