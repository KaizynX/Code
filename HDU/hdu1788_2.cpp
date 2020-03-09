/*
 * @Author: Kaizyn
 * @Date: 2020-03-08 14:32:44
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-08 14:35:13
 * @FilePath: \Code\HDU\hdu1788_2.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 20;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

long long lcm(const long long &a, const long long &b)
{
    return a/__gcd(a, b)*b;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, a;
    while (cin >> n >> a && n|a) {
        long long res = 1;
        for (int i = 1, m; i <= n; ++i) {
            cin >> m;
            res = lcm(res, m);
        }
        cout << res-a << endl;
    }
    return 0;
}