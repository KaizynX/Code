/*
 * @Author: Kaizyn
 * @Date: 2020-03-18 13:53:27
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-18 15:46:58
 * @FilePath: \Code\codeforces\cf1325E_2.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
int a[N], d[N];
set<int> e[N];
vector<int> des, edge[N];

void update(int &x, const int &y)
{
    if (y != -1 && (x == -1 || x > y)) x = y;
}

inline int bfs(const int &s)
{
    memset(d, 0, sizeof d);
    queue<pii> q;
    int res = -1;
    q.push({s, -1});
    d[s] = 1;
    while (q.size()) {
        int u = q.front().first,
            fa = q.front().second;
        q.pop();
        for (int v : e[u]) if (v != fa) {
            if (d[v]) {
                update(res, d[u]+d[v]-1);
            } else {
                d[v] = d[u]+1;
                q.push({v, u});
            }
        }
    }
    return res;
}

inline int solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int maxa = 0;
    for (int i = 1; i <= n; ++i) {
        maxa = max(maxa, a[i]);
        for (int j = 2, k; j*j <= a[i]; ++j) {
            if (a[i]%j) continue;
            k = 0;
            while (a[i]%j == 0) a[i] /= j, ++k;
            if (k&1) edge[i].emplace_back(j);
        }
        if (a[i] > 1) edge[i].emplace_back(a[i]);
        if (!edge[i].size()) return 1;
        if (edge[i].size() == 1) edge[i].emplace_back(1);
        for (int &j : edge[i]) des.emplace_back(j);
    }
    sort(des.begin(), des.end());
    des.erase(unique(des.begin(), des.end()), des.end());
    for (int i = 1, u, v; i <= n; ++i) {
        for (int &j : edge[i])
            j = lower_bound(des.begin(), des.end(), j)-des.begin();
        u = edge[i][0]; v = edge[i][1];
        if (e[u].count(v) || e[v].count(u)) return 2;
        e[u].insert(v); e[v].insert(u);
    }
    if (des[0] == 1) e[0].clear();
    int res = -1;
    for (int i = 0; i < (int)des.size() && des[i]*des[i] <= maxa; ++i) {
        update(res, bfs(i));
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << solve() << endl;
    return 0;
}