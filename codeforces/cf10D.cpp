#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 5e2+7;

int n, m;
int a[N], b[N], dp[N][N], path[N][N], last[N][N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> b[i];
    b[0] = -1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) {
                last[i][j] = i;
                for (int k = 0; k < j; ++k) {
                    if (b[k] < a[i]) {
                        // dp[i][j] = max(dp[i][j], dp[i-1][k]+1);
                        if (dp[i-1][k]+1 > dp[i][j]) {
                            dp[i][j] = dp[i-1][k]+1;
                            path[i][j] = k;
                        }
                    }
                }
            } else {
                dp[i][j] = dp[i-1][j];
                last[i][j] = last[i-1][j];
            }
        }
    }
#ifdef DEBUG
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            cout << "[" << i << ", " << j << "] "
                 << last[i][j] << " " << path[i][j] << endl;
        }
    }
#endif
    int resj = 0;
    for (int j = 1; j <= m; ++j) {
        if (dp[n][j] > dp[n][resj])
            resj = j;
    }
    cout << dp[n][resj] << endl;
    vector<int> v;
    for (int i = last[n][resj], j = resj; j; ) {
        v.push_back(b[j]);
        j = path[i][j];
        i = last[i][j];
    }
    reverse(v.begin(), v.end());
    for (int i : v) cout << i << " ";
    cout << endl;
    return 0;
}
