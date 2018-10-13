#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n, m;
long long ans, f[Maxn];

int main()
{
	cin >> n >> m;
	for(int i = min(n, m); i; --i)
	{
		f[i] = 1ll*(n/i)*(m/i);
		for(long long j = i+i; j <= min(n, m); j += i)
			f[i] -= f[j];
		ans += f[i]*i;
	}
	cout << ans*2-1ll*n*m << endl;
	return 0;
}
