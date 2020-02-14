#include <bits/stdc++.h>

using namespace std;

const int N = 5e2+7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int n, m, s, t, dd, dt;
int dis[N], path[N];
vector<pii> ed[N], et[N];
vector<int> pd, pt;

inline void dijskra(vector<pii> e[])
{
    memset(dis, 0x3f, sizeof dis);
    memset(path, -1, sizeof path);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    dis[s] = 0;
    while (q.size()) {
        pii u = q.top();
        q.pop();
        if (u.first > dis[u.second]) continue;
        if (u.second == t) break;
        for (pii v : e[u.second]) {
            int tmp = v.first+u.first;
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
        ed[u].emplace_back(d, v);
        et[u].emplace_back(t, v);
        if (one) continue;
        ed[v].emplace_back(d, u);
        et[v].emplace_back(t, u);
    }
    cin >> s >> t;
    dijskra(et);
    dt = dis[t];
    getpath(pt);
    dijskra(ed);
    dd = dis[t];
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

