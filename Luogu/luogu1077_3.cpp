#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int Maxn = 107;
const int Mo = 1000007;

int n, m, pre;
int a[Maxn], f[2][Maxn];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", a+i);
	for(int i = 0; i <= m; ++i) f[0][i] = 1;
	for(int i = 1; i <= n; ++i) // the kind i flower
	{
		// for(int j = 0; j <= m; ++j) f[i&1][j] = 0;
		memset(f[i&1], 0, sizeof(int)*Maxn);
		for(int j = 0; j <= a[i]; ++j) // take j this kind flower
		{
			for(int k = min(pre+j, m); k-j >= 0; --k)
				f[i&1][k] = (f[i&1][k] + f[(i-1)&1][k-j]) % Mo;
		}
		pre = min(m, pre+a[i]);
	}
	printf("%d\n", f[n&1][m]);
	return 0;
}

