#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int Maxn = 10000+5;
const int Maxm = 20000+5;

struct E
{
	int u,v;
	bool operator < (const E &another)const
	{
		return v<another.v;
	}
}e[Maxm];

int n,m,ans,num;
int c[Maxn],v[Maxn];
int pos[Maxn];
bool vis[Maxn];

void dfs(int now,int s)
{
	if(s>=n)//有环
	{
		printf("Poor Xed\n");
		exit(0);
	}
	vis[now]=1;
	v[now]=max(v[now],s);//优先满足高奖金
	for(int i=pos[now-1]+1;i<=pos[now];++i)
	{
		dfs(e[i].u,v[now]+1);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&e[i].u,&e[i].v);
		c[e[i].u]++;
	}
	sort(e+1,e+m+1);//按 v 排
	//确定该点对应边的位置
	int last=0;
	for(int i=1;i<=m;++i)
	{
		pos[ e[i].v ]=i;
		if(last != e[i].v)
		{
			for(int j=last+1;j<i;++j)
				pos[j]=pos[last];
			last=e[i].v;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(c[i]==0)//食物链最底端
			dfs(i,0);
	}
	for(int i=1;i<=n;++i)
	{
		if(vis[i]==1)num++;
		ans+=v[i];
	}
	if(num<n)//是否遍历所有，判断环
	{
		printf("Poor Xed\n");
		return 0;
	}
	ans+=n*100;
	printf("%d\n",ans);
	return 0;
}
