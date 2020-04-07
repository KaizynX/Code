/*
 * @Author: Kaizyn
 * @Date: 2020-04-04 23:10:52
 * @LastEditTime: 2020-04-05 10:12:40
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, k, c;
string s;
int nex[N], dp[N], cnt[N];
int pre[N], dp2[N];

inline void solve()
{
    cin >> n >> k >> c >> s;
    int mv = 0;
    nex[n+1] = n+1;
    for (int i = n; i; --i) {
        if (s[i-1] == 'o') nex[i] = i;
        else nex[i] = nex[i+1];
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = max(dp[i], dp[i-1]);
        mv = max(dp[i], mv);
        if (s[i-1] == 'x') continue;
        // ++cnt[dp[i]];
        if (i+c+1 <= n) {
            int j = nex[i+c+1];
            dp[j] = max(dp[j], dp[i]+1);
        }
    }
    #ifdef DEBUG
    for (int i = 1; i <= n; ++i) cout << dp[i] << " \n"[i==n];
    #endif
    if (mv != k-1) return;
    pre[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i-1] =='o') pre[i] = i;
        else pre[i] = pre[i-1];
    }
    for (int i = 1; i <= n+1; ++i) dp2[i] = mv;
    for (int i = n; i; --i) {
        dp2[i] = min(dp2[i], dp2[i+1]);
        if (s[i-1] == 'x') continue;
        if (i-c-1 >= 1) {
            int j = pre[i-c-1];
            dp2[j] = min(dp2[j], dp2[i]-1);
        }
    }
    #ifdef DEBUG
    for (int i = 1; i <= n; ++i) cout << dp2[i] << " \n"[i==n];
    #endif
    for (int i = 1; i <= n; ++i) {
        if (s[i-1] == 'x') continue;
        if (dp[i] == dp2[i]) ++cnt[dp[i]];
    }
    for (int i = 1; i <= n; ++i) {
        if (s[i-1] == 'x') continue;
        if (dp[i] == dp2[i] && cnt[dp[i]] == 1) cout << i << endl;
    }
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