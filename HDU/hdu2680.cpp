#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const int M = 2e4+7;
const int INF = 1e9;

int n, m, s, t;
int dis[N];
typedef pair<int, int> pii;
vector<pii> e[N];

int main()
{
    while (scanf("%d %d %d", &n, &m, &s) == 3) {
        for (int i = 1; i <= n; ++i) {
            vector<pii>().swap(e[i]);
            dis[i] = INF;
        }
        for (int i = 1, u, v, w; i <= m; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            e[u].emplace_back(w, v);
            //e[v].emplace_back(w, u);
        }
        priority_queue<pii, vector<pii>, greater<pii>> q;
        scanf("%d", &t);
        for (int i = 1, a; i <= t; ++i) {
            scanf("%d", &a);
            q.push({0, a});
        }
        int res = -1;
        while (q.size()) {
            pii u = q.top();
            q.pop();
            if (u.first > dis[u.second]) continue;
            if (u.second == s) {
                res = u.first;
                break;
            }
            for (pii v : e[u.second]) {
                int d = u.first+v.first;
                if (d > dis[v.second]) continue;
                dis[v.second] = d;
                q.push({d, v.second});
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
