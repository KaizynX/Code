/*
 * @Author: Kaizyn
 * @Date: 2020-03-21 17:47:25
 * @LastEditTime: 2020-03-21 19:31:26
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 20;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
int a[N+3][N+3];
int dp[2][1<<N];
vector<int> statu;

inline void solve()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    statu.clear();
    for (int i = 0; i < 1<<n; ++i) {
        if (i&(i>>1)) continue;
        statu.emplace_back(i);
    }
    #ifdef DEBUG
    cout << "size:" << statu.size() << endl;
    #endif
    memset(dp[1], 0, sizeof dp[1]);
    for (int i = 0; i < n; ++i) {
        memset(dp[i&1], 0, sizeof dp[0]);
        for (int j : statu) {
            int sum = 0;
            for (int k = 0; k < n; ++k) if ((j>>k)&1) sum += a[i][k];
            for (int k : statu) {
                if (j&k) continue;
                dp[i&1][j] = max(dp[i&1][j], dp[~i&1][k]+sum);
            }
        }
    }
    int res = 0;
    for (int i : statu) res = max(res, dp[~n&1][i]);
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n) {
        solve();
    }
    return 0;
}