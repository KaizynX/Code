/*
 * @Author: Kaizyn
 * @Date: 2020-03-09 08:23:58
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-09 08:26:48
 * @FilePath: \Code\upc\20200308E.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, s;
vector<int> e[N];

inline void solve()
{
    cin >> n >> s;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += e[i].size() == 1;
    }
    printf("%.2f\n", 2.0*s/cnt);
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