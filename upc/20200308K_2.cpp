/*
 * @Author: Kaizyn
 * @Date: 2020-03-08 20:39:33
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-08 21:03:34
 * @FilePath: \Code\upc\20200308K_2.cpp
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 2e3+7;

int g, num;
int pg[4], pn[4], fac[N][4], c[N][N][4], v[N][N], s[N][N];

inline void init()
{
    int gg = g;
    for (int i = 2; i*i <= gg; ++i) {
        if (gg%i) continue;
        pg[num] = i;
        while (gg%i == 0) gg /= i, ++pn[num];
        ++num;
    }
    if (gg > 1) { pg[num] = gg; pn[num] = 1; ++num; }

    for (int i = 1, x; i <= 2000; ++i) {
        x = i;
        for (int j = 0; j < num; ++j) {
            while (x%pg[j] == 0) x /= pg[j], ++fac[i][j];
        }
    }
    // fac[i] = i!
    for (int i = 1; i <= 2000; ++i) {
        for (int j = 0; j < num; ++j) {
            fac[i][j] += fac[i-1][j];
        }
    }
    for (int i = 1; i <= 2000; ++i) {
        for (int j = 1; j <= i; ++j) {
            v[i][j] = 1;
            for (int k = 0; k < num; ++k) {
                // C(i, j) = i!/j!/(i-j)!
                c[i][j][k] = fac[i][k]-fac[j][k]-fac[i-j][k];
                v[i][j] &= c[i][j][k] >= pn[k];
                // c[i][j][k] = min(c[i][j][k], pn[k]);
                // for (int l = 1; l <= c[i][j][k]; ++l) v[i][j] *= pg[k];
            }
        }
    }
    for (int i = 1; i <= 2000; ++i) {
        for (int j = 1; j <= 2000; ++j) {
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+v[i][j];
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, n, m;
    scanf("%d%d", &T, &g);
    init();
    while (T--) {
        scanf("%d %d", &n, &m);
        m = min(n, m);
        printf("%d\n", s[n][m]);
    }
    return 0;
}