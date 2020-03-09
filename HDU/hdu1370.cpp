/*
 * @Author: Kaizyn
 * @Date: 2020-03-08 13:52:17
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-08 15:31:03
 * @FilePath: \Code\HDU\hdu1370.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n = 3, d, cir = 21252;
int a[5], m[5] = {0, 23, 28, 33};

void exgcd(int a, int b, int &x, int &y)
{
    if (!b) x = 1, y = 0;
    else exgcd(b, a%b, y, x), y -= a/b*x;
}

inline int mul_inverse(const int &a, const int &m)
{
    int x, y;
    exgcd(a, m, x, y);
    return (x%m+m)%m;
}

inline int CRT(int a[], int m[])
{
    int res = 0, M = 1;
    for (int i = 1; i <= n; ++i)
        M *= m[i];
    for (int i = 1; i <= n; ++i)
        res = (res + a[i]*(M/m[i])*mul_inverse(M/m[i], m[i]))%M;
    return (res+M)%M;
}

signed main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int id = 0;
        while (scanf("%d %d %d %d", a+1, a+2, a+3, &d) == 4) {
            if (a[1] == -1 && a[2] == -1 && a[3] == -1 && d == -1) break;
            // for (int i = 1; i <= n; ++i) a[i] = (m[i]-a[i]%m[i])%m[i];
            for (int i = 1; i <= n; ++i) a[i] %= m[i];
            int res = (CRT(a, m)-d+cir)%cir;
            if (!res) res = cir;
            printf("Case %d: the next triple peak occurs in %d days.\n", ++id, res);
        } 
    }
    return 0;
}