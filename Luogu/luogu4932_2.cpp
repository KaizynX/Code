#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e7+7;

int n, a, b, c, d, x, sum[2];

int main()
{
	cin >> n >> a >> b >> c >> d >> x;
	for(int i = 1, tmp, cnt; i <= n; ++i)
	{
		tmp = x = (int)((1ll*a*x%d*x%d + 1ll*b*x + c)%d);
		cnt = 0;
		while(tmp)
		{
			cnt += tmp&1;
			tmp >>= 1;
		}
		sum[cnt&1]++;
	}
	cout << 1ll*sum[0]*sum[1] << endl;
	return 0;
}
