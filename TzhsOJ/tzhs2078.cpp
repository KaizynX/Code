#include <iostream>
#include <cstdio>
#define DEBUG

using namespace std;

const int Maxn = 107;

int n, k;
int f[2][Maxn];

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1, tmp; i <= n; ++i)
	{
		scanf("%d", &tmp);
		for(int v = 0, nex; v < k; ++v)
		{
			nex = (f[(i+1)&1][v] + tmp) % k; // (i-1)&1 == (i+1)&1
			f[i&1][nex] = max(f[i&1][nex], f[(i+1)&1][v] + tmp); // dp
			f[(i+1)&1][v] = f[i&1][v]; // copy
#ifdef DEBUG
			printf("%d %d\n", nex, f[i&1][nex]);
#endif
		}
	}
	printf("%d\n", f[n&1][0]);
	return 0;
}
