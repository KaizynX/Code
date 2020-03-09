/*
 * @Author: Kaizyn
 * @Date: 2020-03-07 12:35:49
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-07 13:37:28
 * @FilePath: \Code\HDU\hdu4652.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e6+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int k, m, n;
double f[N];

inline double solve0()
{
    f[0] = 0; f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        f[i] = (m+1)*f[i-1]-m*f[i-2];
    }
    return f[n];
}

inline double solve1()
{
    f[0] = 0; f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        f[i] = (2.0*m-i+1)/(m-i+1)*f[i-1]-1.0*m/(m-i+1)*f[i-2];
    }
    return f[n];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    while (cin >> T) {
        while (T--) {
            cin >> k >> m >> n;
            printf("%.7f\n", k ? solve1() : solve0());
        }
    }
    return 0;
}