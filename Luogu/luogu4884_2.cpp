#include <bits/stdc++.h>

using namespace std;

long long k, m;
map<__int128, int> mmp;

void write (__int128 x)
{
	if(x < 0) x = -x, putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

int main()
{
	cin >> k >> m;
	// 10^n (%m) = 9k+1 (%m)
	long long t = sqrt(m);
	k = (k*9+1)%m;
	__int128 tmp = 1; // tmp = 10^i
	for(int i = 0; i < t; ++i)
	{
		mmp[k*tmp%m] = i;
		tmp = tmp*10%m;
	}
	// now tmp = 10^t
	__int128 now = tmp; // now = (10^t)^i
	for(int i = 1; i <= t; ++i)
	{
		if(mmp.count(now))
		{
			__int128 ans = 1ll*i*t-mmp[now];
			if(ans > 0)
			{
				write(ans);
				putchar('\n');
				return 0;
			}
		}
		now = now*tmp%m;
	}
	write(-1);
	putchar('\n');
	return 0;
}
