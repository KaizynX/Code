#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int Maxm=2*1e5+5,Maxn=1*1e4+5;

int n,m,first,tail,tot,s,t;//tot记录邻接表里边的数量
int x[Maxm],y[Maxm],nextt[Maxm*2],to[Maxm*2],head[Maxm],q[Maxn],step[Maxn];
bool vis[Maxn];

void add(int a,int b)//邻接表
{
	to[++tot]=b;
	nextt[tot]=head[a];
	head[a]=tot;
}

void bfs1()//直通终点的点
{
	q[0]=t;
	vis[t]=1;
	first=0;
	tail=1;
	while(first<tail)
	{
		int u=q[first++];
		for(int i=head[u];i!=0;i=nextt[i])
		{
			if(vis[ to[i] ]==0)
			{
				vis[ to[i] ]=1;
				q[tail++]=to[i];
			}
		}
	}
}

bool chubian(int q)//判断是否所有出边都直接或间接与终点相连
{
	for(int i=head[q];i!=0;i=nextt[i])
	{
		if(vis[ to[i] ]==0)return 0;
	}
	return 1;
}

bool bfs2()
{
	first=0;
	tail=1;
	q[0]=s;
	step[s]=0;
	while(first<tail)
	{
		int u=q[first++];
		if(chubian(u)==0)continue;
		for(int i=head[u];i!=0;i=nextt[i])
		{
			if(step[ to[i] ]==-1)
			{
				step[ to[i]]=step[u]+1;
				q[tail++]=to[i];
				if(to[i]==t)//找到终点
				{
					printf("%d",step[ to[i] ]);
					return 1;
				}
			}
		}
	}
	return false;
}

int main()
{
	memset(vis,0,sizeof vis);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",x+i,y+i);
		add(y[i],x[i]);//反着加
	}
	scanf("%d%d",&s,&t);
	bfs1();
	memset(head,0,sizeof head);
	memset(step,-1,sizeof step);
	memset(q,0,sizeof q);
	memset(nextt,0,sizeof nextt);
	memset(to,0,sizeof to);
	tot=0;
	for(int i=1;i<=m;++i)
	{
		add(x[i],y[i]);//顺着找最短路径
	}
	if(vis[s]==0)
	{
		printf("-1\n");
		return 0;
	}
	if(bfs2()==0)
		printf("-1\n");

	return 0;
}
