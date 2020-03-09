/*
 * @Author: Kaizyn
 * @Date: 2020-03-08 18:26:49
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-09 08:22:56
 * @FilePath: \Code\upc\20200308A.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
int a[N], dp[N][N];

inline int solve()
{
    for (int len = 3; len <= n; ++len) {
        for (int i = 1, j; (j = i+len-1) <= n; ++i) {
            dp[i][j] = 0;
            for (int k = i+1; k < j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]+a[i]*a[j]*a[k]);
            }
        }
    }
    return dp[1][n];
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    scanf("%d", &testcase);
    for (int t = 1; t <= testcase; ++t) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", a+i);
        printf("Case #%d: %d\n", t, solve());
    }
    return 0;
}