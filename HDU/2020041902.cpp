/*
 * @Author: Kaizyn
 * @Date: 2020-04-19 13:46:21
 * @LastEditTime: 2020-04-19 13:50:30
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, m, k;
int a[N][N];

inline int dis(const int &x, const int &y) {
    return abs(x-(n+1)/2)+abs(y-m/2);
}

inline void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j] = 0;
        }
    }
    int resx = 0, resy = 0;
    for (int i = 1, x, y; i <= k; ++i) {
        cin >> x >> y;
        a[x][y] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (a[i][j] || a[i][j+1]) continue;
            if (dis(i, j) < dis(resx, resy)) {
                resx = i;
                resy = j;
            }
        }
    }
    if (!resx) puts("-1");
    else {
        printf("(%d,%d) (%d,%d)\n", resx, resy, resx, resy+1);
    }
}

signed main()
{
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}