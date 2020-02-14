#include <bits/stdc++.h>

using namespace std;

const int N = 5e2+7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int n, m, s, t, dd, dt;
pii dis[N];
int path[N];
vector<piii> ed[N], et[N];
vector<int> pd, pt;

inline void dijskra(vector<piii> e[])
{
    for (int i = 0; i < n; ++i) dis[i] = {INF, INF};
    memset(path, -1, sizeof path);
    priority_queue<piii, vector<piii>, greater<piii>> q;
    dis[s] = {0, 0};
    q.push({dis[s], s});
    while (q.size()) {
        piii u = q.top();
        q.pop();
        if (u.first > dis[u.second]) continue;
        if (u.second == t) break;
        for (piii v : e[u.second]) {
            pii tmp = {u.first.first+v.first.first, u.first.second+v.first.second};
            if (tmp >= dis[v.second]) continue;
            dis[v.second] = tmp;
            path[v.second] = u.second;
            q.push({tmp, v.second});
        }
    }
}

inline void getpath(vector<int> &p)
{
    for (int i = t; i != s; i = path[i])
        p.emplace_back(i);
    p.emplace_back(s);
    reverse(p.begin(), p.end());
}

inline void print(vector<int> &p)
{
    for (unsigned i = 0; i < p.size(); ++i)
        cout << p[i] << (i+1 == p.size() ? "\n" : " => ");
}

int main()
{
    cin >> n >> m;
    for (int i = 1, u, v, d, t, one; i <= m; ++i) {
        cin >> u >> v >> one >> d >> t;
        ed[u].push_back({{d, 1}, v});
        et[u].push_back({{t, d}, v});
        if (one) continue;
        ed[v].push_back({{d, 1}, u});
        et[v].push_back({{t, d}, u});
    }
    cin >> s >> t;
    dijskra(et);
    dt = dis[t].first;
    getpath(pt);
    dijskra(ed);
    dd = dis[t].first;
    getpath(pd);

    cout << "Time = " << dt;
    if (pt == pd) {
        cout << "; ";
    } else {
        cout << ": ";
        print(pt);
    }
    cout << "Distance = " << dd << ": ";
    print(pd);
    return 0;
}
