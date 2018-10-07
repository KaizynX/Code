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
//谁知道是不是单链
//邻接表
int u[Maxn*2],v[Maxn*2],fir[Maxn*2],nex[Maxn*2];

int main()
{
	scanf("%d",&n);
	//输入边
	for(int i=1;i<n;++i)//1~n-1
	{
		scanf("%d%d",u+i,v+i);
		nex[i] = fir[ u[i] ];
		fir[ u[i] ] = i;
	}
	//无向连通图,反着连一边
	for(int i=1;i<n;++i)//n+1~2n
	{
		int now_i(n+i);
		v[now_i]=u[i];
		u[now_i]=v[i];
		nex[now_i] = fir[ u[now_i] ];
		fir[ u[now_i] ] = now_i;
	}
	//输入权值
	for(int i=1;i<=n;++i)
	{
		scanf("%d",w+i);
	}
	//暴力便利每一个点
	//关于vis:
	for(int i=1;i<=n;++i)
	{
		memset(vis,0,sizeof vis);//把上一个点的终点标记去掉
		vis[i]=true;//防止自己和自己链接
		//距离为1
		for(int p1=fir[i];p1;p1=nex[p1])
		{
			int v1(v[p1]);
			if(vis[v1])continue;
			else vis[v1]=true;
			//距离为2
			for(int p2=fir[v1];p2;p2=nex[p2])
			{
				int v2(v[p2]),now_w(w[i]*w[v2]);
				//防止重复添加，如果遇到小环
				if(vis[v2])continue;
				else vis[v2]=true;
				ans_max=max(ans_max,now_w);
				ans_sum=(ans_sum+now_w)%mo;
				//终点不能重复vis[v2]!=false
			}
			vis[v1]=false;//中间道路可以重复
		}
		//vis[i]=false;//因为memset没有必要
	}
	printf("%d %d\n",ans_max,ans_sum);
	return 0;
}
