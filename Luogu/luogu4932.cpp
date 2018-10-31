#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e7+7;

int n, a, b, c, d;
int x[Maxn];
long long ans;

int main()
{
	cin >> n >> a >> b >> c >> d >> x[0];
	for(int i = 1; i <= n; ++i)
	{
		x[i] = (int)((1ll*a*x[i-1]%d*x[i-1]%d + 1ll*b*x[i-1] + c)%d);
		for(int j = 1; j < i; ++j)
		{
			int tmp = x[i]^x[j], cnt = 0;
			while(tmp)
			{
				cnt += tmp&1;
				tmp >>= 1;
			}
			ans += cnt&1;
		}
	}
	cout << ans << endl;
	return 0;
}
