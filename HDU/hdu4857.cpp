/*
 * @Author: Kaizyn
 * @Date: 2020-05-08 18:50:35
 * @LastEditTime: 2020-05-08 19:12:44
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 3e4+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, m;
int deg[N];
vector<int> res;
vector<int> e[N];
// priority_queue<int, vector<int>, greater<int>> q;
priority_queue<int> q;

inline void solve()
{
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        // e[u].emplace_back(v);
        // ++deg[v];
        e[v].emplace_back(u);
        ++deg[u];
    }
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 0) q.push(i);
    }
    while (q.size()) {
        int u = q.top();
        q.pop();
        // cout << u << " ";
        res.emplace_back(u);
        for (const int &v : e[u]) {
            if (--deg[v] == 0) q.push(v);
        }
        vector<int>().swap(e[u]);
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " \n"[i==n-1];
    }
    vector<int>().swap(res);
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}