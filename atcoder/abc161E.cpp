/*
 * @Author: Kaizyn
 * @Date: 2020-04-04 23:10:52
 * @LastEditTime: 2020-04-04 23:40:45
 */
#include <bits/stdc++.h>

// #define DEBUG

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

inline void solve()
{
    cin >> n >> k >> c >> s;
    nex[n+1] = n+1;
    for (int i = n; i; --i) {
        if (s[i-1] == 'o') nex[i] = i;
        else nex[i] = nex[i+1];
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = max(dp[i], dp[i-1]);
        if (s[i-1] == 'x') continue;
        ++cnt[dp[i]];
        if (i+c+1 <= n) {
            int j = nex[i+c+1];
            dp[j] = max(dp[j], dp[i]+1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (s[i-1] == 'o' && cnt[dp[i]] == 1)
            cout << i << endl;
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