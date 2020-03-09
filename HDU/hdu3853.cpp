/*
 * @Author: Kaizyn
 * @Date: 2020-03-06 20:57:06
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-06 21:19:19
 * @FilePath: \Code\HDU\hdu3853.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int MOD = 1e9+7;
const double eps = 1e-9;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m;
double p[N][N][3], f[N][N];

inline double solve()
{
    f[n][m] = 0;
    for (int i = n; i; --i) {
        for (int j = m; j; --j) {
            if (1-p[i][j][0] < eps) continue;
            f[i][j] = (p[i][j][1]*f[i][j+1]+p[i][j][2]*f[i+1][j]+2)/(1-p[i][j][0]);
        }
    }
    return f[1][1];
}

int main()
{
    while (scanf("%d %d", &n, &m) == 2) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                for (int k = 0; k < 3; ++k)
                    scanf("%lf", &p[i][j][k]);
        printf("%.3f\n", solve());
    }
    return 0;
}