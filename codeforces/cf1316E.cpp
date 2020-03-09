/*
 * @Author: Kaizyn
 * @Date: 2020-03-05 10:44:06
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-05 11:45:20
 * @FilePath: \Code\codeforces\cf1316E.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int P = 7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const long long INF = 1e18;
typedef pair<int, int> pii;

struct Node
{
    int a, s[P];
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.a > n2.a;
    }
} a[N];

int n, p, k;
int cnt[1<<P];
long long sum[N], dp[N][1<<P];

inline void solve()
{
    cin >> n >> p >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].a;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < p; ++j)
            cin >> a[i].s[j];

    sort(a+1, a+n+1);
    for (int i = 0; i < 1<<p; ++i)
        cnt[i] = __builtin_popcount(i);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i-1]+a[i].a;
    fill(dp[0], dp[0]+(1<<p), -INF);
    dp[0][0] = 0;

    for (int i = 1; i <= p+k; ++i) {
        for (int j = 0; j < 1<<p; ++j) {
            if (i-cnt[j] > k) continue;
            dp[i][j] = dp[i-1][j];
            for (int l = 0; l < p; ++l) if ((j>>l)&1) {
                long long tmp = dp[i-1][j^(1<<l)]+a[i].s[l]-a[i].a;
                dp[i][j] = max(dp[i][j], tmp);
            }
        }
    }
    for (int i = 0; i < 1<<p; ++i) {
        dp[k+cnt[i]][i] += sum[k+cnt[i]];
    }
    for (int i = k+1; i <= n; ++i) {
        for (int j = 0; j < 1<<p; ++j) {
            if (i-cnt[j] <= k) continue;
            dp[i][j] = dp[i-1][j];
            for (int l = 0; l < p; ++l) if ((j>>l)&1) {
                long long tmp = dp[i-1][j^(1<<l)]+a[i].s[l];
                dp[i][j] = max(dp[i][j], tmp);
            }
        }
    }
    cout << dp[n][(1<<p)-1] << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}