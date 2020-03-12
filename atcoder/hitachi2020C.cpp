/*
 * @Author: Kaizyn
 * @Date: 2020-03-12 16:51:33
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-12 19:58:19
 * @FilePath: \Code\atcoder\hitachi2020C.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
int col[N], res[N];
vector<int> e[N], a[2], b[3];

void dfs(const int &u, const int &fa)
{
    col[u] = col[fa]^1;
    a[col[u]].emplace_back(u);
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
    for (int i = 1; i <= n; ++i) b[i%3].emplace_back(i);
    if (a[0].size() > a[1].size()) swap(a[0], a[1]);
    if ((int)a[0].size() <= n/3) {
        for (int i : a[0]) {
            res[i] = b[0].back();
            b[0].pop_back();
        }
        for (int i : a[1]) {
            for (int j = 0; j < 3; ++j) {
                if (b[j].empty()) continue;
                res[i] = b[j].back();
                b[j].pop_back();
                break;
            }
        }
    } else {
        for (int i : b[1]) {
            res[a[0].back()] = i;
            a[0].pop_back();
        }
        for (int i : b[2]) {
            res[a[1].back()] = i;
            a[1].pop_back();
        }
        for (int i : b[0]) {
            int t = a[0].size() ? 0 : 1;
            res[a[t].back()] = i;
            a[t].pop_back();
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