#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=52;
int m,n,map[N][N];
long long ans,f[N][N];

long long dp()
{
	memset(f,0,sizeof f);
	long long res=0;
	for(int i=m;i>=1;--i)
		for(int j=n;j>=1;--j)
		{
			f[i][j]=max(f[i+1][j],f[i][j+1])+map[i][j];
			res=max(res,f[i][j]);
		}
	return res;
}

void dfs(int x,int y,int v)
{
	if(x==m&&y==n)
	{
		ans=max(ans,v+dp());
		return;
	}
	if(x<1||y<1||x>m||y>n)return;
	
	int nv=v+map[x][y];
	map[x][y]=0;
	dfs(x+1,y,nv);
	dfs(x,y+1,nv);
	map[x][y]=nv-v;
}

int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&map[i][j]);
	dfs(1,1,0);
	printf("%ld\n",ans);
	return 0;
}
