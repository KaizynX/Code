#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
const int Maxn=1e4+5,Maxm=2*1e5+5;

int n,m,S,T;
int u[Maxm],v[Maxm],fir[Maxm],nex[Maxm];
int head,tail,q_point[Maxn],q_depth[Maxn];//ģ�����
bool to_T[Maxn];//�Ƿ����г��߶�ֱ�ӻ������յ���ͨ
bool vis[Maxn];

inline void in();
inline void init_to_T()
{
	//��T��ʼ���ſ���
	int now_point,now_i;
	q_point[++tail]=T;
	to_T[T]=1;
	while(head<tail)
	{
		now_point=q_point[++head];
		now_i=fir[now_point];
		//�ڽӱ����
		while(now_i!=0)
		{
			if(to_T[ u[now_i] ]==0)
			{
				to_T[ u[now_i] ]=1;
				q_point[++tail]=u[now_i];
			}
			now_i=nex[now_i];
		}
	}

	for(int i=1;i<=n;++i)
	{
		if(to_T[i]==1)continue;
		now_i=fir[i];
		while(now_i!=0)
		{
			to_T[ u[now_i] ]=0;
			now_i=nex[now_i];
		}
	}

	if(to_T[S]==0)//S��ֱ�ӻ������յ���ͨ
	{
		printf("-1\n");
		exit(0);
	}
}

inline void solve ()
{
	int now_i,now_point,now_depth,now_u;
	head=0;
	tail=0;
	memset(q_point,0,sizeof q_point);
	//memset(q_depth,0,sizeof q_depth);
	q_point[++tail]=T;
	//q_depth[tail]=0;
	vis[T]=1;
	while(head<tail)
	{
		++head;
		now_point=q_point[head];
		now_depth=q_depth[head];
		if(now_point==S)
		{
			printf("%d\n",now_depth);
			exit(0);
		}
		now_i=fir[now_point];
		while(now_i!=0)
		{
			now_u=u[now_i];
			if(to_T[now_u]==1)
			{
				if(vis[ now_u ]==0)
				{
					vis[ now_u ]=1;
					++tail;
					q_point[tail]=now_u;
					q_depth[tail]=now_depth+1;
				}
			}
			now_i=nex[now_i];
		}
	}
}

int main()
{
	in();
	init_to_T();//��ʼ��to_T[]
	solve();//Ѱ�����·��
	return 0;
}

inline void in()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",u+i,v+i);//uָ��v
		//�ڽӱ�洢,��v����u
		nex[i] = fir[ v[i] ];
		fir[ v[i] ] = i;
	}
	scanf("%d%d",&S,&T);
	if(S==T)//tm����
	{
		printf("0\n");
		exit(0);
	}
}
