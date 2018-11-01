#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int Q, a;
char s[Maxn];
long double v[128];

inline void init()
{
	for(int i = '1'; i < 128; ++i) v[i] = (long double)log10(i-'0');
}

int main()
{
	init();
	scanf("%d", &Q);
	while(Q--)
	{
		scanf("%d", &a);
		scanf("%s", s);
		long double ans = (long double)log10(a)*(1ll*a*(a+1)/2);
		for(int i = 0; i <= a; ++i) ans += v[s[i]];
		printf("%lld\n", (long long)ans+1);
	}
	return 0;
}
