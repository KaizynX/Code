/*
 * @Author: Kaizyn
 * @Date: 2020-03-05 16:01:48
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-05 16:03:43
 * @FilePath: \Code\Luogu\luoguSP1026.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;

inline void solve()
{
    cin >> n;
    double res = 0;
    for (int i = 1; i <= n; ++i) res += 1.0*n/i;
    printf("%.2f\n", res);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}