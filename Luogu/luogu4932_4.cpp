#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e7+7;

int n, a, b, c, d, x, sum[2];

int main()
{
	cin >> n >> a >> b >> c >> d >> x;
	for(int i = 1; i <= n; ++i)
	{
		x = (int)((1ll*a*x%d*x%d + 1ll*b*x + c)%d);
		sum[__builtin_popcount(x)&1]++;
	}
	cout << 1ll*sum[0]*sum[1] << endl;
	return 0;
}
