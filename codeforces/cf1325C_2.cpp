/*
 * @Author: Kaizyn
 * @Date: 2020-03-14 23:59:39
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-15 00:10:17
 * @FilePath: \Code\codeforces\cf1325C_2.cpp
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
int res[N];
vector<int> e[N];
map<pii, int> mp;

inline void solve()
{
    cin >> n;
    memset(res, -1, sizeof res);
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        mp[{u, v}] = mp[{v, u}] = i;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (e[i].size() >= 3) {
            for (int j = 0; j < 3; ++j) {
                int t = mp[{i, e[i][j]}];
                res[t] = j;
            }
            break;
        }
    }
    for (int i = 1, v = n-2; i < n; ++i) {
        if (res[i] == -1) res[i] = v--;
    }
    for (int i = 1; i < n; ++i) {
        cout << res[i] << endl;
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