#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int Maxn = 10000+5;
const int Maxm = 200000+5;

int n,m,S,T,ans;
int head,tail,q_point[Maxn],q_depth[Maxn];//队列
bool to_T[Maxn];//是否出边全指向终点；将指向（不指向终点）点==0
bool vis[Maxn];
//邻接表
int u[Maxm],v[Maxm],fir[Maxm],nex[Maxm];

inline void in();//输入
inline void init();//初始化co_T , to_T
inline void clear();//初始化队列,vis
inline void q_push(int point,int depth=0)//入队列
{
	tail++;
	q_point[tail]=point;
	q_depth[tail]=depth;
}
inline void q_pop(int &point,int &depth)//出队列
{
	head++;
	point=q_point[head];
	depth=q_depth[head];
}
inline bool bfs()//从终点开始宽搜找到起点
{
	//特殊情况
	if(to_T[S]==0)
	{
		printf("-1\n");
		return 0;
	}
	else if(S==T)
	{
		printf("0\n");
		return 0;
	}

	int now_point,now_depth,cur;
	clear();
	q_push(T);
	vis[T]=1;
	while(head<tail)
	{
		q_pop(now_point,now_depth);
		cur=fir[now_point];
		
		while(cur!=0)
		{
			//找的起点
			if(u[cur]==S)
			{
				ans=now_depth+1;//S为下一个点
				return 1;
			}
			//符合路径上的点出边指向终点
			if(to_T[ u[cur] ]==1)
			{
				if(vis[ u[cur] ]==0)
				{
					q_push(u[cur],now_depth+1);
					vis[ u[cur] ]=1;
				}
			}
			cur=nex[cur];
		}
	}
	return 1;//???
}

int main()
{
	in();
	init();
	if(bfs())//bfs return 1说明需要输出ans
		printf("%d\n",ans);
	return 0;
}

inline void in()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		//邻接表,以指向的点为标记
		scanf("%d%d",u+i,v+i);
		nex[i]=fir[ v[i] ];
		fir[ v[i] ]=i;
	}
	//起始点和终点
	scanf("%d%d",&S,&T);
}

inline void init()
{
	int now_point,now_depth,cur;
	clear();
	q_push(T);
	to_T[T]=1;//
	while(head<tail)
	{
		q_pop(now_point,now_depth);
		cur=fir[now_point];
		while(cur!=0)
		{
			if(to_T[ u[cur] ]==0)
			{
				q_push(u[cur]);
				to_T[ u[cur] ]=1;//
			}
			cur=nex[cur];
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(to_T[i]==0)//不能通向终点的点
		{
			cur=fir[i];
			while(cur!=0)//把通向（这些点）的标记
			{
				to_T[ u[cur] ]=0;
				cur=nex[cur];
			}
		}
	}
}

inline void clear()
{
	head=0;
	tail=0;
	memset(q_point,0,sizeof q_point);
	memset(q_depth,0,sizeof q_depth);
}

