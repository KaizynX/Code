#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e3+7;

int n;
int a[N], dp[N][N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i][i] = a[i]*n;
    }
    for (int len = 2; len <= n; ++len) {
        for (int l = 1, r; (r = l+len-1) <= n; ++l) {
            dp[l][r] = max(dp[l+1][r]+a[l]*(n-len+1), dp[l][r-1]+a[r]*(n-len+1));
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}
