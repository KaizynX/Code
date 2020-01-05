#include <bits/stdc++.h>

using namespace std;

const int N = 3e3+7;

int n, res;
int a[N], b[N], dp[N][N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1, val; i <= n; ++i) {
        val = 0;
        for (int j = 1; j <= n; ++j) {
            if (a[i] == b[j]) dp[i][j] = val+1;
            else dp[i][j] = dp[i-1][j];
            if (b[j] < a[i]) val = max(val, dp[i-1][j]);
            res = max(res, dp[i][j]);
        }
    }
    cout << res << endl;
    return 0;
}
