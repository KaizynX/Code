#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 1e4+7;
const int val[10] = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int n, m;
int vis[10], dp[N][10], last[N][10], cnt[10];

int main()
{
    cin >> n >> m;
    for (int i = 1, a; i <= m; ++i) {
        cin >> a;
        vis[a] = 1;
    }
    if (vis[5]) vis[3] = vis[2] = 0;
    if (vis[3]) vis[2] = 0;
    if (vis[9]) vis[6] = 0;

    int maxj = 0;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= 9; ++i) dp[0][i] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 9; j; --j) {
            if (!vis[j]) continue;
            if (i-val[j] < 0) continue;
            for (int k = 9; k; --k) {
                if (!vis[k] || dp[i-val[j]][k] == -1) continue;
                int now = dp[i-val[j]][k]+1;
                if (now > dp[i][j]) {
                    dp[i][j] = now;
                    last[i][j] = k;
                }
            }
            if (i == n && dp[n][j] > dp[n][maxj]) maxj = j;
        }
    }
    for (int i = n, j; i > 0; ) {
#ifdef DEBUG
        cout << i << " " << maxj << endl;
#endif
        ++cnt[maxj];
        j = maxj;
        maxj = last[i][j];
        i -= val[j];
    }
    for (int i = 9; i; --i) {
        for (int j = 1; j <= cnt[i]; ++j) {
            cout << i;
        }
    }
    cout << endl;
    return 0;
}
