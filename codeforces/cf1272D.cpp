#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n;
int a[N];
int dp[2][N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        dp[0][i] = (a[i] > a[i-1] ? dp[0][i-1]+1 : 1);
        dp[1][i] = (a[i] > a[i-1] ? dp[1][i-1]+1 : 1);
        if (i > 2 && a[i] > a[i-2]) dp[1][i] = max(dp[1][i], dp[0][i-2]+1);
        res = max(res, dp[0][i]);
        res = max(res, dp[1][i]);
    }
    cout << res << endl;
    return 0;
}
