#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn = 50+5;

int m,n,ans;//mÐÐnÁÐ
int a[Maxn][Maxn],c[Maxn][Maxn];
bool vis[Maxn][Maxn];

int cul()
{
	//memset(c,0,sizeof c);
	int down,right;
	for(int i=m;i>=1;--i)
	{
		for(int j=n;j>=1;--j)
		{
			if(vis[i+1][j]==1)down=0;
			else down=c[i+1][j];
			if(vis[i][j+1]==1)right=0;
			else right=c[i][j+1];
			c[i][j]=a[i][j]+max(down,right);
		}
	}
	return c[1][1];
}

void dfs(int x,int y,int s)
{
	if(x>m || y>n)return;
	if(x==m && y==n)//a[m][n]==0
	{
		ans=max( cul() +s,ans);
		return;
	}
	vis[x][y]=1;
	dfs(x+1,y,s+a[x][y]);
	dfs(x,y+1,s+a[x][y]);
	vis[x][y]=0;
}

int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			scanf("%d",&a[i][j]);
		}
	}
	dfs(1,1,0);
	printf("%d\n",ans);
	return 0;
}
