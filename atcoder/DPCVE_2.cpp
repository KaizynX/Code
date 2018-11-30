#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;
const int MOD = 998244353;

int n, a[Maxn];
long long dp[Maxn];
// dp[i][j] = (i-1)*dp[i-1][j]+a[i]*dp[i-1][j-1]

int main()
{
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a+1, a+n+1);
	dp[1] = a[1];
	for(int i = 2; i <= n; ++i)
		for(int j = i; j; --j)
			dp[j] = dp[j]*(i-1)+dp[j-1]*a[i];
	long long ans = dp[1];
	for(int i = 2; i <= n; ++i)
		ans = __gcd(ans, dp[i]);
	cout << ans%MOD << endl;
	return 0;
}
