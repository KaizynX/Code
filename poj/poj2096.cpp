/*
 * @Author: Kaizyn
 * @Date: 2020-03-07 11:25:16
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-07 11:32:59
 * @FilePath: \Code\poj\poj2096.cpp
 */
#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1e3+7;

int n, s;
double f[N][N];

int main()
{
    scanf("%d%d", &n, &s);
    f[n][s] = 0;
    for (int i = s; i >= 0; --i) {
        for (int j = n; j >= 0; --j) {
            if (i == s && j == n) continue;
            f[i][j] = (1.0*(s-i)/s*(n-j)/n*f[i+1][j+1]+
                       1.0*i/s*(n-j)/n*f[i][j+1]+
                       1.0*(s-i)/s*j/n*f[i+1][j]+1)/(1-1.0*i/s*j/n);
        }
    }
    printf("%.4f\n", f[0][0]);
    return 0;
}