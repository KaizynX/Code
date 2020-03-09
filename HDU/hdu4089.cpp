/*
 * @Author: Kaizyn
 * @Date: 2020-03-07 16:31:25
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-08 10:20:38
 * @FilePath: \Code\HDU\hdu4089.cpp
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 2e3+1;
const double eps = 1e-6;

int n, m, k;
double p1, p2, p3, p4;
double f[N][N];

int main()
{
    #define b2 (p2/(1-p1))
    #define b3 (p3/(1-p1))
    #define b4 (p4/(1-p1))
    while (scanf("%d %d %d %lf %lf %lf %lf", &n, &m, &k, &p1, &p2, &p3, &p4) == 7) {
        if (p4 < eps) { puts("0.00000"); continue; }
        /* f[i][j] i people Tom at j
         * f[i][1] = p1*f[i][1]+p2*f[i][i]+p4
         * f[i][j] = p1*f[i][j]+p3*f[i][j-1]+p3*f[i-1][j-1]+p4 (1 < j <= k)
         * f[i][j] = p1*f[i][j]+p3*f[i][j-1]+p3*f[i-1][j-1]    (k < j <= i)
        */
        f[1][1] = p4/(1-p1-p2);
        for (int i = 2; i <= n; ++i) {
            double p = 1.0;
            f[i][i] = 0;
            for (int j = i; j > k; --j, p *= b2)
                f[i][i] += p*(b3*f[i-1][j-1]);
            for (int j = k; j > 1; --j, p *= b2)
                f[i][i] += p*(b3*f[i-1][j-1]+b4);
            f[i][i] = (f[i][i]+p*b4)/(1-p*b2);
            f[i][1] = b2*f[i][i]+b4;
            for (int j = 2; j <= k; ++j)
                f[i][j] = b2*f[i][j-1]+b3*f[i-1][j-1]+b4;
            for (int j = k+1; j < i; ++j)
                f[i][j] = b2*f[i][j-1]+b3*f[i-1][j-1];
        }
        printf("%.5f\n", f[n][m]);
    }
    #undef b2
    #undef b3
    #undef b4
    return 0;
}