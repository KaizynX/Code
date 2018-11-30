#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+7;
const int MOD = 998244353;

int n, a[Maxn];
long long dp[Maxn][Maxn];
// dp[i][j] [1, i] form j circle, the sum of product
// add i'th to any circle, no difference 
// and the way to insert i is i-1 dp[i][j] += (i-1)*dp[i-1][j]
// form a now circle, the vale is a[i] dp[i][j] += dp[i-1][j-1]*a[i]

int main()
{
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a+1, a+n+1);
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= i; ++j)
			dp[i][j] = dp[i-1][j]*(i-1)+dp[i-1][j-1]*a[i];
	long long ans = dp[n][1];
	for(int i = 2; i <= n; ++i)
		ans = __gcd(ans, dp[n][i]);
	cout << ans%MOD << endl;
	return 0;
}
