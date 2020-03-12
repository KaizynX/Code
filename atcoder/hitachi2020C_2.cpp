/*
 * @Author: Kaizyn
 * @Date: 2020-03-12 17:04:25
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-12 19:51:16
 * @FilePath: \Code\atcoder\hitachi2020C_2.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;

int n;
int col[N], res[N];
vector<int> e[N], p[2];

void dfs(const int &u, const int &fa)
{
    col[u] = col[fa]^1;
    p[col[u]].emplace_back(u);
    for (int v : e[u]) if (v != fa) dfs(v, u);
}

inline void solve()
{
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs(1, 0);
    if (p[0].size() > p[1].size()) swap(p[0], p[1]);
    if ((int)p[0].size() <= n/3) {
        for (int i = 0; i < (int)p[0].size(); ++i) {
            res[i*3+3] = p[0][i];
        }
        for (int i = 1, j = 0; i <= n; ++i) if (!res[i]) {
            res[i] = p[1][j++];
        }
    } else {
        for (int i = 0; i < n; i += 3) {
            if (i+1 > n) break;
            res[i+1] = p[0].back();
            p[0].pop_back();
            if (i+2 > n) break;
            res[i+2] = p[1].back();
            p[1].pop_back();
        }
        for (int i = 1; i <= n; ++i) {
            if (res[i]) continue;
            if (p[0].size()) {
                res[i] = p[0].back();
                p[0].pop_back();
            } else {
                res[i] = p[1].back();
                p[1].pop_back();
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << " \n"[i==n];
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