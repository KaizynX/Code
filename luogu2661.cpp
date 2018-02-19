#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int Maxn = 2*1e5+5;

int n,ans=Maxn;//���Ļ�=n
int a[Maxn],d[Maxn];
bool vis[Maxn];

void dfs(int point,int depth)
{
	if(a[point]==0)return;//�˳�ѭ��
	if(vis[point] && depth>d[point])//�ҵ���
	{
		ans=min(ans,depth-d[point]);
		a[point]=0;//ɾ���õ�,��ֹ�ظ�
		vis[point]=false;//ͬ��
		return ;
	}

	vis[point]=true;//���,�һ�
	d[point]=depth;//�������(ʱ���?)�󻷵Ĵ�С
	dfs(a[point],depth+1);
	a[point]=0;//ɾ���û��йص����е�
	vis[point]=false;//��ֹ��С���ҵ���
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	//�����ж����,����ÿ����
	for(int i=1;i<=n;++i)
	{
		dfs(i,1);
	}
	printf("%d\n",ans);
	return 0;
}
