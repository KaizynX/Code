/*
 * @Author: Kaizyn
 * @Date: 2020-03-07 11:44:20
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-07 11:50:18
 * @FilePath: \Code\HDU\hdu4405.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m;
double f[N];
map<int, int> to;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n >> m && n|m) {
        to.clear();
        for (int i = 1, x, y; i <= m; ++i) {
            cin >> x >> y;
            to[x] = y;
        }
        f[n] = 0;
        for (int i = n-1; i >= 0; --i) {
            if (to.count(i)) { f[i] = f[to[i]]; continue; } 
            f[i] = 0;
            for (int j = 1; j <= 6 && i+j <= n; ++j) f[i] += f[i+j];
            f[i] = f[i]/6+1;
        }
        printf("%.4f\n", f[0]);
    }
    return 0;
}