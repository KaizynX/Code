#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn = 100 + 5;

int n;
int a[Maxn*3];
int f[Maxn][Maxn];
// Max_ans <= 2.1 * 10^9
// f[i][j] i 到 j 最大的能量

int main()
{
	scanf("%d",&n);
	for(int i(1); i <= n; ++i)
	{
		scanf( "%d", a+i );
		a[i + n * 2]=a[i + n] = a[i];
	}
	for(int len(2); len <= n; ++len)
	{
		for(int i(1); i <= n*3 - len + 1; ++i)
		{
			int j = i + len - 1;
			for(int k(i); k < j; ++k)
			{
				f[i][j] = max( f[i][j], f[i][k]);
			}
		}
	}

	int ans(0);
	for(int i(1); i <= 2*n + 1; ++i)
		ans = max(ans, f[i][i+n-1]);
	printf("%d\n",ans);
	return 0;
}
