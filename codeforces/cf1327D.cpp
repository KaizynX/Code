/*
 * @Author: Kaizyn
 * @Date: 2020-03-23 22:25:45
 * @LastEditTime: 2020-03-24 00:25:31
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

int f(int s, int gap, int len, int dep)
{
    if (len&1) {
        int col = a[s];
        for (int i = s, j = 1; j <= len; i += gap, ++j) {
            if (a[i] != col) { col = -1; break; }
        }
        if (col != -1) res = min(res, dep);
        return col;
    } else {
        int cl = f(s, gap*2, len/2, dep+1),
            cr = f(s+gap, gap*2, len/2, dep+1);
        if (cl == -1 || cr == -1 || cl != cr) return -1;
        res = min(res, dep);
        return cl;
    }
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
        f(1, 1, m, 1);
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