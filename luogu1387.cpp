#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 100 + 7;

int n,m,ans;
int a[Maxn][Maxn], f[Maxn][Maxn];

inline int min3 (int a, int b, int c)
{
	return min(a,min(b,c));
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; ++ i)
	{
		for(int j = 1; j <= m; ++ j)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i = 1; i <= n; ++ i)
	{
		for(int j = 1; j <= m; ++ j)
		{
			if(a[i][j])
				f[i][j] = min3(f[i-1][j],f[i-1][j-1],f[i][j-1]) + 1;
			//else f[i][j] = 0;
			if(f[i][j] > ans) ans = f[i][j];
		}
	}
	printf("%d\n",ans);
	return 0;
}
