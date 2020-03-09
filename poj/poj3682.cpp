/*
 * @Author: Kaizyn
 * @Date: 2020-03-06 19:58:34
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-06 20:07:05
 * @FilePath: \Code\poj\poj3682.cpp
 */
#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1e3+7;

int k;
double p, f[N], g[N];

int main()
{
    while (cin >> k && k) {
        cin >> p;
        for (int i = 1; i <= k; ++i) {
            f[i] = f[i-1]+1/p;
            g[i] = g[i-1]+2*f[i-1]+1+(2*f[i]+1)*(1-p)/p;
        }
        printf("%.3f %.3f\n", f[k], g[k]);
    }
    return 0;
}