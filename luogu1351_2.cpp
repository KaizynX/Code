#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int Maxn = 2*1e5+5;
const int Mo = 10007;// wi <= 1e4

int n,ans_max,ans_sum;
int w[Maxn];
//邻接表
int u[Maxn*2],v[Maxn*2],fir[Maxn*2],nex[Maxn*2];
inline void connect(int i)//邻接表的加边操作
{
	nex[i] = fir[ u[i] ];
	fir[ u[i] ] = i;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;++i)//n-1条
	{
		//无向边
		int i_1(i*2-1),i_2(i*2);
		scanf("%d%d",u+i_1,v+i_1);
		connect(i_1);
		//反向
		u[i_2]=v[i_1];
		v[i_2]=u[i_1];
		connect(i_2);
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%d",w+i);
	}
	/*因为:无向连通图+ n-1条边
	 *所以:没有环
	 *因为:所求距离为2
	 *所以:以一个点为中心,它所连通的点之间两两互为所求
	 *     thisPoint_sum = 求和 (w_all - w_one)*w_one
	 *                   = w_all * w_all - 求和 w_one * w_one
	 */
	int w_all,sum_one,w_max1,w_max2;
	for(int i=1;i<=n;++i)
	{
		//如果该节点只有一个连通点,不用担心
		//w_max2 = 0 && w_all = sum_one
		w_all=0;
		sum_one=0;
		w_max1=0;//第一大
		w_max2=0;//第二大
		for(int p=fir[i];p;p=nex[p])
		{
			int now_v = v[p];

			w_all = (w_all + w[now_v])%Mo;
			sum_one = ( sum_one + ( w[now_v]*w[now_v] )%Mo )%Mo;

			if(w[now_v]>w_max1)
			{
				w_max1=w[now_v];
			}
			//else 最大比剩下了再选第二大
			else if(w[now_v]>=w_max2)// >= 第一大 和 第二大 一样大
			{
				w_max2=w[now_v];
			}
		}
		ans_sum=( ans_sum + w_all*w_all - sum_one )%Mo;
		ans_max=max(ans_max,w_max1*w_max2);
	}
	printf("%d %d\n",ans_max,ans_sum);
	return 0;
}
