#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 107;
const int Mo = 1000007;

int n, m, pre;
int a[Maxn], f[Maxn][Maxn];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", a+i);
	for(int i = 0; i <= m; ++i) f[0][i] = 1;
	for(int i = 1; i <= n; ++i) // the kind i flower
	{
		for(int j = 0; j <= a[i]; ++j) // take j this kind flower
		{
			for(int k = min(pre+j, m); k-j >= 0; --k)
				f[i][k] = (f[i][k] + f[i-1][k-j]) % Mo;
		}
		pre = min(m, pre+a[i]);
	}
	printf("%d\n", f[n][m]);
	return 0;
}
