#include <iostream>
#include <cstdio>
#define DEBUG

using namespace std;

const int Maxn = 107;

int n, k;
int f[Maxn][Maxn];

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1, tmp; i <= n; ++i)
	{
		scanf("%d", &tmp);
		for(int v = 0, nex; v < k; ++v)
		{
			nex = (tmp + v) % k;
			if(f[i-1][v]) f[i][nex] = max(f[i-1][nex], f[i-1][v] + tmp);
#ifdef DEBUG
			printf("%d %d\n", v, f[i][v]);
#endif
		}
		f[i][tmp%k] = max(f[i][tmp%k], tmp);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) ans = max(ans ,f[i][0]);
	printf("%d\n", ans);
	return 0;
}

