#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e7+7;

int n;
int p[Maxn], np[Maxn], tot;
long long f[Maxn], ans;

inline void prime()
{
	np[1] = 1;
	for(int i = 2; i <= n; ++i)
	{
		if(!np[i]) p[++tot] = i;
		for(int j = 1; j <= tot && p[j]*i <= n; ++j)
		{
			np[p[j]*i] = 1;
			if(i%p[j] == 0) break;
		}
	}
}

int main()
{
	scanf("%d", &n);
	prime();
	for(int i = n; i > 1; --i)
	{
		f[i] = 1ll*(n/i)*(n/i);
		for(int j = i+i; j <= n; j += i)
			f[i] -= f[j];
		if(!np[i]) ans += f[i];
	}
	printf("%lld\n", ans);
	return 0;
}
