/*
 * @Author: Kaizyn
 * @Date: 2020-03-23 22:25:45
 * @LastEditTime: 2020-03-24 08:56:05
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m, res;
int p[N], c[N];
int a[N], vis[N];

inline bool check(int d)
{
    for (int i = 1; i <= d; ++i) {
        int col = a[i];
        for (int j = i; j <= m; j += d) {
            if (a[j] != col) { col = -1; break; }
        }
        if (col != -1) return true;
    }
    return false;
}

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i) cin >> c[i];

    res = n;
    memset(vis, 0, sizeof(int)*(n+3));
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        a[m = 1] = c[i];
        vis[i] = 1;
        for (int j = p[i]; j != i; j = p[j]) {
            a[++m] = c[j];
            vis[j] = 1;
        }
        for (int j = 1; j*j <= m; ++j) {
            if (m%j) continue;
            if (check(j)) res = min(res, j);
            if (m/j != j && check(m/j)) res = min(res, m/j);
        }
    }
    cout << res << endl;
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