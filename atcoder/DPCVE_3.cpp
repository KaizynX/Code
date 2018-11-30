#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;
const int MOD = 998244353;

int n, a[Maxn];

int main()
{
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a+1, a+n+1);
	int ans = a[1];
	for(int i = 2; i <= n; ++i)
		ans = int(1ll*ans*__gcd(a[i], i-1)%MOD);
	cout << ans << endl;
	return 0;
}
