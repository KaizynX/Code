#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 100+5;

int n,m,a[Maxn][Maxn],r[Maxn],c[Maxn];
bool flag=1;

void dfs(int cur,int step)
{
	if(flag==0)return;
	if(step>n)
	{
		flag=0;
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(a[cur][i]==1)
		{
			dfs(i,step+1);
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&m);
		while(m!=0)
		{
			a[i][m]=1;
			r[m]++;
			c[i]++;
			scanf("%d",&m);
		}
	}
	m=0;
	for(int i=1;i<=n;++i)
	{
		if(r[i]==0)m=i;
		if(r[i]==0 && c[i]==0)
		{
			printf("NO\n");
			return 0;
		}
	}
	if(m==0)
	{
		printf("NO\n");
		return 0;
	}
	dfs(m,1);
	if(flag)printf("YES\n");
	else printf("NO\n");
	return 0;
}
