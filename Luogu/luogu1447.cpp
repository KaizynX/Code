#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+7;

int n, m;
long long ans;

int main()
{
	cin >> n >> m;
	for(int i = 1, x, y, gcd, k; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			gcd = __gcd(i, j);
			x = i/gcd; y = j/gcd;
			k = min(n/x-i/x, m/y-j/y);
			ans += k*2+1;
		}
	cout << ans << endl;
	return 0;
}
