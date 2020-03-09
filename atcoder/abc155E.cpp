#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e6+7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

int n;
int dp[N][2];
string s;

inline void solve()
{
    cin >> s;
    n = s.size();
    dp[n][0] = 0; dp[n][1] = INF;
    for (int i = n-1, x; i >= 0; --i) {
        // dp[i][?] whether pay s[i] make difference to s[i-1]
        x = s[i]-'0';
        dp[i][0] = x+min(dp[i+1][0], dp[i+1][1]);
        dp[i][1] = 1+min({dp[i+1][0]+10-x, dp[i+1][1]+8-x});
        #ifdef DEBUG
        cout << dp[i][0] << " " << dp[i][1] << endl;
        #endif
    }
    cout << min(dp[0][0], dp[0][1]) << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}