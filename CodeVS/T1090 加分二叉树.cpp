#include <cstdio>
const int N=35;
long long f[N][N];
int g[N][N],a[N],n;
void dfs(int l,int r)
{
	if(l>r)return;
	printf("%d ",g[l][r]);
	dfs(l,g[l][r]-1);
	dfs(g[l][r]+1,r);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		f[i][i]=a[i];
		g[i][i]=i;
		f[i][i-1]=1;
	}
	for(int i=n;i>=1;--i)
		for(int j=i+1;j<=n;++j)
			for(int k=i;k<=j;++k)
			{
				int now=f[i][k-1]*f[k+1][j]+a[k];
				if(now>f[i][j])
				{
					f[i][j]=now;
					g[i][j]=k;
				}
			}
	printf("%d\n",f[1][n]);
	dfs(1,n);
	return 0;
}
