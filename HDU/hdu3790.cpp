#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const int INF = 1e9;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;
int n, m, s, t;
vector<piii> e[N];
pii dis[N];

inline pii dijskra()
{
    priority_queue<piii, vector<piii>, greater<piii>> q;
    q.push({{0, 0}, s});
    dis[s] = {0, 0};
    while (q.size()) {
        piii u = q.top();
        q.pop();
        // cout << u.first.first << " " << u.first.second << " " << u.second << endl;
        if (u.first > dis[u.second]) continue;
        if (u.second == t) return u.first;
        for (piii v : e[u.second]) {
            int d = u.first.first+v.first.first,
                p = u.first.second+v.first.second;
            if (make_pair(d, p) >= dis[v.second]) continue;
            dis[v.second] = {d, p};
            q.push({{d, p}, v.second});
        }
    }
    return {-1, -1};
}

int main()
{
    while (scanf("%d %d", &n, &m) == 2 && n|m) {
        for (int i = 1; i <= n; ++i) {
            vector<piii>().swap(e[i]);
            dis[i] = {INF, INF};
        }
        for (int i = 1, u, v, d, p; i <= m; ++i) {
            scanf("%d %d %d %d", &u, &v, &d, &p);
            e[u].push_back({{d, p}, v});
            e[v].push_back({{d, p}, u});
        }
        scanf("%d %d", &s, &t);
        pii res = dijskra();
        printf("%d %d\n", res.first, res.second);
    }
    return 0;
}
