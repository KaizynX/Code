/*
 * @Author: Kaizyn
 * @Date: 2020-03-04 09:49:45
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-04 17:05:40
 * @FilePath: \Code\codeforces\cf1305D_5.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
set<int> e[N], leaf;
int f[N], vis[N], die[N], inq[N];

inline int query(const int &u, const int &v)
{
    int res;
    cout << "? " << u << " " << v << endl;
    cout.flush();
    cin >> res;
    return res;
}

inline void answer(const int &res)
{
    cout << "! " << res << endl;
    cout.flush();
    exit(0);
}

void del(const int &u, const int &fa, const int &w)
{
    if (leaf.find(u) != leaf.end()) leaf.erase(u);
    for (int v : e[u]) {
        if (v == fa) continue;
        if (v == w) e[w].erase(u);
        else del(v, u, w);
    }
}

inline void solve()
{
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].insert(v);
        e[v].insert(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (e[i].size() == 1) leaf.insert(i);
    }
    while (leaf.size() > 1) {
        int u = *leaf.begin();
        leaf.erase(leaf.begin());
        int v = *leaf.begin();
        leaf.erase(leaf.begin());
        int w = query(u, v);
        if (u == w || u == v) answer(w);
        del(u, -1, w);
        del(v, -1, w);
        if (e[w].size() <= 1) leaf.insert(w);
    }
    answer(*leaf.begin());
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}
