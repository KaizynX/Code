/*
 * @Author: Kaizyn
 * @Date: 2020-04-26 17:06:58
 * @LastEditTime: 2020-04-26 18:15:02
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e3+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

struct Node {
    int x, p;
    friend bool operator < (const Node &lhs, const Node &rhs) {
        return lhs.x > rhs.x;
    }
};

int n;
Node a[N];
long long dp[N][N];
// dp[i][j] take i, j on left

inline void solve()
{
    cin >> n;
    for (int i = 1, x; i <= n; ++i) {
        cin >> a[i].x;
        a[i].p = i;
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]+1ll*a[i].x*abs(n-(i-j)+1-a[i].p));
        }
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1ll*a[i].x*abs(j-a[i].p));
        }
    }
    long long res = 0;
    for (int i = 0; i <= n; ++i) res = max(res, dp[n][i]);
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}