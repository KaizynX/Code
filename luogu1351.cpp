#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int Maxn = 2*1e5 +5;
const int mo = 10007;

int n,ans_sum,ans_max;
int w[Maxn];
bool vis[Maxn];
//˭֪���ǲ��ǵ���
//�ڽӱ�
int u[Maxn*2],v[Maxn*2],fir[Maxn*2],nex[Maxn*2];

int main()
{
	scanf("%d",&n);
	//�����
	for(int i=1;i<n;++i)//1~n-1
	{
		scanf("%d%d",u+i,v+i);
		nex[i] = fir[ u[i] ];
		fir[ u[i] ] = i;
	}
	//������ͨͼ,������һ��
	for(int i=1;i<n;++i)//n+1~2n
	{
		int now_i(n+i);
		v[now_i]=u[i];
		u[now_i]=v[i];
		nex[now_i] = fir[ u[now_i] ];
		fir[ u[now_i] ] = now_i;
	}
	//����Ȩֵ
	for(int i=1;i<=n;++i)
	{
		scanf("%d",w+i);
	}
	//��������ÿһ����
	//����vis:
	for(int i=1;i<=n;++i)
	{
		memset(vis,0,sizeof vis);//����һ������յ���ȥ��
		vis[i]=true;//��ֹ�Լ����Լ�����
		//����Ϊ1
		for(int p1=fir[i];p1;p1=nex[p1])
		{
			int v1(v[p1]);
			if(vis[v1])continue;
			else vis[v1]=true;
			//����Ϊ2
			for(int p2=fir[v1];p2;p2=nex[p2])
			{
				int v2(v[p2]),now_w(w[i]*w[v2]);
				//��ֹ�ظ���ӣ��������С��
				if(vis[v2])continue;
				else vis[v2]=true;
				ans_max=max(ans_max,now_w);
				ans_sum=(ans_sum+now_w)%mo;
				//�յ㲻���ظ�vis[v2]!=false
			}
			vis[v1]=false;//�м��·�����ظ�
		}
		//vis[i]=false;//��Ϊmemsetû�б�Ҫ
	}
	printf("%d %d\n",ans_max,ans_sum);
	return 0;
}
