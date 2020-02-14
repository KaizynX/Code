#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int M = 1e4+7;
const int INF = 1e6;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int n, k;
int cnt[M];
map<int, int> cnt, a[N];
pii dis[M];
vector<pii> e[M];

int main()
{
    cin >> n;
    for (int i = 1, m; i <= n; ++i) {
        cin >> m;
        for (int j = 1, tmp; j <= m; ++j) {
            cin >> tmp;
            ++cnt[tmp];
            a[i][tmp] = j;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (auto j : a[i]) if (cnt[j.first] > 1) {
            for (auto k : a[j]) if (j != k && cnt[k.first] > 1) {
                e[j.first].emplace_back(abs(j.second-k.second), k.first);
            }
        }
    }
    cin >> k;
    int s, t;
    while (k--) {
        priority_queue<piii> q;
        cin >> x >> y;
        for (int i = 0; i < M; ++i) dis[i] = {INF, INF};
        for (int i = 1; i <= n; ++i) if (a[i].count(x)) {
            for (auto p : a[i]) if (cnt[p.first] > 1) {
                dis[p.first] = min(dis[p.first], {abs(a[i][x]-p.second), 0});
                q.push({dis[p.first], i});
            }
        }
        while (q.size()) {
            piii u = q.top();
            q.pop();
            if (u.first < dis[u.second]) continue;
            for (pii v : e[u.second]) {
                pii tmp = {u.first.first+v.first, u.first.second+1};
                if (tmp >= dis[v.second]) continue;
                dis[v.second] = tmp;
                q.push({tmp, v.second});
            }
        }
        for (int i = 1; i <= n; ++i) if (a[i].count(y)) {
            for (auto p : a[i]) if (cnt[p.first] > 1) {
                ;
            }
        }
    }
    return 0;
}
