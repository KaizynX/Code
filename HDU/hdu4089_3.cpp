/*
 * @Author: Kaizyn
 * @Date: 2020-03-07 23:45:12
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-08 10:28:07
 * @FilePath: \Code\HDU\hdu4089_3.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e3+1;
const double eps = 1e-6;

int n, m, k;
int sum[N];
double p1, p2, p3, p4;
double buf[N*N/2], pp[N], c[N];

inline double& f(const int &i, const int &j) { return buf[sum[i-1]+j-1]; }

int main()
{
    #define b2 (p2/(1-p1))
    #define b3 (p3/(1-p1))
    #define b4 (p4/(1-p1))
    for (int i = 1; i <= n; ++i) sum[i] = sum[i-1]+i;
    while (scanf("%d %d %d %lf %lf %lf %lf", &n, &m, &k, &p1, &p2, &p3, &p4) == 7) {
        if (p4 < eps) { puts("0.00000"); continue; }
        /* f[i][j] i people Tom at j
         * f[i][1] = p1*f[i][1]+p2*f[i][i]+p4
         * f[i][j] = p1*f[i][j]+p3*f[i][j-1]+p3*f[i-1][j-1]+p4 (1 < j <= k)
         * f[i][j] = p1*f[i][j]+p3*f[i][j-1]+p3*f[i-1][j-1]    (k < j <= i)
        */
        pp[0] = 1;
        for (int i = 1; i <= n; ++i) pp[i] = pp[i-1]*b2;
        memset(buf, 0, sizeof buf);
        f(1, 1) = p4/(1-p1-p2);
        c[1] = b4;
        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j <= k; ++j) c[j] = b3*f(i-1, j-1)+b4;
            for (int j = k+1; j <= i; ++j) c[j] = b3*f(i-1, j-1);
            for (int j = 1; j <= i; ++j) f(i, i) += pp[i-j]*c[j];
            f(i, i) /= 1-pp[i];
            f(i, 1) = b2*f(i, i)+c[1];
            for (int j = 2; j < i; ++j) {
                f(i, j) = b2*f(i, j-1)+c[j];
            }
        }
        printf("%.5f\n", f(n, m));
    }
    #undef b2
    #undef b3
    #undef b4
    return 0;
}