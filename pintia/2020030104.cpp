#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 3e3+7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

int n;
int a[N<<1];
long long dp[N<<1][N<<1];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = n+1; i <= 2*n; ++i) a[i] = a[i-n];
    for (int len = 1; len <= n; ++len) {
        for (int l = 1, r; (r = l+len-1) <= 2*n; ++l) {
            for (int k = l; k < r; ++k) {
                dp[l][r] = max(dp[l][r], dp[l][k]+dp[k+1][r]+abs(a[l]-a[k+1]));
            }
        }
    }
    long long res = 0;
    for (int l = 1, r; (r = l+n-1) <= 2*n; ++l) {
        res = max(res, dp[l][r]);
    }
    cout << res << endl;
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