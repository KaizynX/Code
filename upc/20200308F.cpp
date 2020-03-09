/*
 * @Author: Kaizyn
 * @Date: 2020-03-08 19:10:09
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-08 19:27:55
 * @FilePath: \Code\upc\20200308F.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 65;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m;
int a[N][N], res[N][N], tmp[N][N];

inline void mul(int x[N][N], int y[N][N])
{
    for (int i = 1; i <= 2*n; ++i) {
        for (int j = 1; j <= 2*n; ++j) {
            tmp[i][j] = 0;
            for (int k = 1; k <= 2*n; ++k) {
                (tmp[i][j] += (int)(1ll*x[i][k]*y[k][j]%MOD)) %= MOD;
            }
        }
    }
    for (int i = 1; i <= 2*n; ++i) {
        for (int j = 1; j <= 2*n; ++j) {
            x[i][j] = tmp[i][j];
        }
    }
}

inline void solve()
{
    /* | A E | ^ (m+1) = | A^m E+A+A^2+..+A^m |
     * | O E |           | O   E              |
     */
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        a[i][i+n] = a[i+n][i+n] = 1;
    }
    for (int i = 1; i <= 2*n; ++i) {
        res[i][i] = 1;
    }
    // qpow a^(m+1)
    ++m;
    while (m) {
        if (m&1) mul(res, a);
        mul(a, a);
        m >>= 1;
    }
    for (int i = 1; i <= n; ++i) --res[i][i+n];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d%c", res[i][j+n], " \n"[j==n]);
        }
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