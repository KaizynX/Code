/*
 * @Author: Kaizyn
 * @Date: 2020-05-02 09:54:54
 * @LastEditTime: 2020-05-02 10:17:36
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 5e2+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, k;
int a[N], b[N];
long long dp[2][N][N];

inline void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    memset(dp[0], 0x8f, sizeof dp[0]);
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        memset(dp[i&1], 0x8f, sizeof dp[i&1]);
        for (int aa = 0, bb; aa <= min(a[i], k-1); ++aa) {
            bb = (a[i]+b[i]-aa+k)%k;
            if (bb > b[i]) continue;
            for (int aaa = 0; aaa < k; ++aaa) {
                for (int bbb = 0; bbb < k; ++bbb) {
                    long long val = dp[~i&1][aaa][bbb]+(aaa+aa >= k)+(bbb+bb >= k)+(a[i]+b[i]-aa-bb)/k;
                    dp[i&1][(aaa+aa)%k][(bbb+bb)%k] = max(dp[i&1][(aaa+aa)%k][(bbb+bb)%k], val);
                }
            }
        }
#ifdef DEBUG
        for (int aaa = 0; aaa < k; ++aaa) {
            for (int bbb = 0; bbb < k; ++bbb) {
                cout << dp[i&1][aaa][bbb] << " \n"[bbb==k-1];
            }
        }
        cout << endl;
#endif
    }
    long long res = 0;
    for (int aaa = 0; aaa < k; ++aaa) {
        for (int bbb = 0; bbb < k; ++bbb) {
            res = max(res, dp[n&1][aaa][bbb]);
        }
    }
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