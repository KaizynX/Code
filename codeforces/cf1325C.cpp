/*
 * @Author: Kaizyn
 * @Date: 2020-03-14 22:43:01
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-14 23:29:15
 * @FilePath: \Code\codeforces\cf1325C.cpp
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
int res[N];
set<int> e[N];
map<pii, int> mp;
queue<int> q;

inline void solve()
{
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        mp[{u, v}] = mp[{v, u}] = i;
        e[u].insert(v);
        e[v].insert(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (e[i].size() == 1) q.push(i);
    }
    int t = n-1;
    while (q.size()) {
        int u = q.front();
        q.pop();
        int v = *e[u].begin();
        res[mp[{u, v}]] = --t;
        e[v].erase(u);
        if (e[v].size() == 1) q.push(v);
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