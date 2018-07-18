#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e4 + 7;

int v, n, c;
int f[Maxn];

int main()
{
	scanf("%d%d%d", &v, &n, &c);
	for(int i = 0, k, m; i < n; ++i)
	{
		scanf("%d%d", &k, &m);
		for(int j = c; j >= m; --j)
			f[j] = max(f[j], f[j-m] + k);
	}
	if(f[c] < v)
	{
		puts("Impossible");
		return 0;
	}
	int cur = c;
	while(f[cur] >= v) --cur;
	printf("%d\n", c-(cur+1) );
	return 0;
}
