#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn = 100+5;
const int Maxm = 10000+5;

int n,m;
int a[Maxn];
int f[Maxn][Maxm];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(j==a[i])f[i][j]=f[i-1][j]+1;
			else if(j>a[i])f[i][j]=f[i-1][j]+f[i-1][j-a[i]];
			else if(j<a[i])f[i][j]=f[i-1][j];
		}
	}
	printf("%d\n",f[n][m]);
	return 0;
}
