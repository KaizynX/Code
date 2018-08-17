#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e5+7;

int m, n;
int st[Maxn][20], log2[Maxn];
// st[i][j] [i-2^j+1, i]

int main()
{
	scanf("%d%d", &m, &n);
	for(int i = 2; i <= m; ++i) log2[i] = log2[i>>1]+1;
	for(int i = 1; i <= m; ++i)
	{
		scanf("%d", &st[i][0]);
		for(int j = 1; j <= log2[i]; ++j)
			st[i][j] = min(st[i][j-1], st[i-(1<<(j-1))][j-1]);
	}
	int l, r, k;
	while(n--)
	{
		scanf("%d%d", &l, &r);
		k = log2[r-l+1];
		printf("%d", min(st[r][k], st[l+(1<<k)-1][k]));
		putchar((n ? ' ' : '\n'));
	}
	return 0;
}
