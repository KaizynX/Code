#include <bits/stdc++.h>

using namespace std;

const int N = 18;
const int M = 51;
const int MOD = 1e9+7;
typedef pair<int, int> pii;

int n;
int a[N][2], dp[1<<N][M];

inline void update(int &x, const int &y)
{
    if (x == -1 || y < x) x = y;
}

inline void solve()
{
    cin >> n;
    for (int j = 0; j < 2; ++j)
        for (int i = 0; i < n; ++i)
            cin >> a[i][j];

    memset(dp, -1, sizeof dp);
    dp[0][1] = 0;
    for (int i = 1; i < 1<<n; ++i) {
        int t = __builtin_popcount(i)-1;
        for (int p = 0; p < n; ++p) if ((i>>p)&1) {
            int j = a[p][abs(t-p)&1], num = 0;
            for (int k = p+1; k < n; ++k) num += (i>>k)&1;
            for (int k = 1; k <= j; ++k) if (dp[i^(1<<p)][k] != -1) {
                update(dp[i][j], dp[i^(1<<p)][k]+num);
            }
        }
    }
    int res = -1;
    for (int j = 0, i = (1<<n)-1; j < M; ++j) if (dp[i][j] != -1) {
        update(res, dp[i][j]);
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