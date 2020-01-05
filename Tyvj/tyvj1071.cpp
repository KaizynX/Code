#include <bits/stdc++.h>

using namespace std;

const int N = 3e3+7;

int n;
int a[N], b[N];
int dp[N][N], s[N][N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) {
        // s[i][j] = max(dp[i-1][k]) k < j , b[k] < a[i]
        for (int j = 1; j <= n; ++j) {
            if (b[j-1] < a[i]) s[i][j] = max(s[i][j-1], dp[i-1][j-1]);
            else s[i][j] = s[i][j-1];
            if (a[i] == b[j]) dp[i][j] = s[i][j]+1;
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}
