/*
 * @Author: Kaizyn
 * @Date: 2020-03-18 17:25:37
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-18 17:35:14
 * @FilePath: \Code\codeforces\cf1325F_2.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m, sq;
int dep[N], used[N];
vector<int> e[N], cir;

void dfs(const int &u)
{
    cir.emplace_back(u);
    dep[u] = cir.size();
    for (int v : e[u]) {
        if (!dep[v]) dfs(v);
        else if (dep[u]-dep[v]+1 >= sq) {
            cout << 2 << endl
                 << dep[u]-dep[v]+1 << endl;
            while (true) {
                cout << cir.back() << " ";
                if (cir.back() == v) break;
                cir.pop_back();
            }
            cout << endl;
            exit(0);
        }
    }
    if (!used[u]) for (int v : e[u]) used[v] = 1;
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
    dfs(1);
    cout << 1 << endl;
    for (int i = 1, cnt = 0; i <= n && cnt < sq; ++i) {
        if (!used[i]) {
            cout << i << " ";
            ++cnt;
        }
    }
    cout << endl;
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