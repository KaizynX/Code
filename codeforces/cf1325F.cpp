/*
 * @Author: Kaizyn
 * @Date: 2020-03-18 16:35:35
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-18 17:36:05
 * @FilePath: \Code\codeforces\cf1325F.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m, sq;
int d[N];
vector<int> e[N], cir, p[N];

void dfs(const int &u)
{
    d[u] = cir.size();
    cir.emplace_back(u);
    for (int v : e[u]) {
        if (d[v] != -1) {
            if (d[u]-d[v]+1 >= sq) {
                cout << 2 << endl
                     << d[u]-d[v]+1 << endl;
                while (true) {
                    cout << cir.back() << " ";
                    if (cir.back() == v) break;
                    cir.pop_back();
                }
                cout << endl;
                exit(0);
            }
        } else {
            dfs(v);
        }
    }
    cir.pop_back();
}

inline void solve()
{
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    while (sq*sq < n) ++sq;
    memset(d, -1, sizeof d);
    dfs(1);
    cout << 1 << endl;
    for (int i = 1; i <= n; ++i) {
        p[d[i]%(sq-1)].emplace_back(i);
    }
    for (int i = 0; i < sq; ++i) {
        if ((int)p[i].size() >= sq) {
            for (int j = 0; j < sq; ++j)
                cout << p[i][j] << " \n"[j==sq-1];
            return;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}