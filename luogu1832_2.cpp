#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e3 + 7;

int n;
int prime[Maxn], cnt;
bool not_prime[Maxn];
long long f[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 2; i <= n ;++i)
	{
		if(!not_prime[i]) prime[++cnt] = i;
		for(int j = 1; j <= cnt && prime[j] * i <= n; ++j)
		{
			not_prime[ i * prime[j] ] = true;
			if(i % prime[j] == 0) break;
		}
	}

	f[0] = 1;
	for(int i = 1; i <= cnt; ++i)
		for(int v = prime[i]; v <= n; ++v)
			f[v] += f[v-prime[i]];
	printf("%lld\n", f[n]);
	return 0;
}

