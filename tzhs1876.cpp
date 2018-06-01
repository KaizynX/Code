#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int Maxn = 10000+5;
const int Maxm = 200000+5;

int n,m,S,T,ans;
int head,tail,q_point[Maxn],q_depth[Maxn];//����
bool to_T[Maxn];//�Ƿ����ȫָ���յ㣻��ָ�򣨲�ָ���յ㣩��==0
bool vis[Maxn];
//�ڽӱ�
int u[Maxm],v[Maxm],fir[Maxm],nex[Maxm];

inline void in();//����
inline void init();//��ʼ��co_T , to_T
inline void clear();//��ʼ������,vis
inline void q_push(int point,int depth=0)//�����
{
	tail++;
	q_point[tail]=point;
	q_depth[tail]=depth;
}
inline void q_pop(int &point,int &depth)//������
{
	head++;
	point=q_point[head];
	depth=q_depth[head];
}
inline bool bfs()//���յ㿪ʼ�����ҵ����
{
	//�������
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
			//�ҵ����
			if(u[cur]==S)
			{
				ans=now_depth+1;//SΪ��һ����
				return 1;
			}
			//����·���ϵĵ����ָ���յ�
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
	if(bfs())//bfs return 1˵����Ҫ���ans
		printf("%d\n",ans);
	return 0;
}

inline void in()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		//�ڽӱ�,��ָ��ĵ�Ϊ���
		scanf("%d%d",u+i,v+i);
		nex[i]=fir[ v[i] ];
		fir[ v[i] ]=i;
	}
	//��ʼ����յ�
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
		if(to_T[i]==0)//����ͨ���յ�ĵ�
		{
			cur=fir[i];
			while(cur!=0)//��ͨ����Щ�㣩�ı��
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

