#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e4 + 7;

int n, v;
long long f[Maxn];

int main()
{
	scanf("%d%d", &v, &n);
	f[0] = 1;
	for(int i = 0, a; i < v; ++i)
	{
		scanf("%d", &a);
		for(int j = a; j <= n; ++j)
			f[j] += f[j-a];
	}
	printf("%lld\n", f[n]);
	return 0;
}
