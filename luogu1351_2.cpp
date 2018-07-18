#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int Maxn = 2*1e5+5;
const int Mo = 10007;// wi <= 1e4

int n,ans_max,ans_sum;
int w[Maxn];
//�ڽӱ�
int u[Maxn*2],v[Maxn*2],fir[Maxn*2],nex[Maxn*2];
inline void connect(int i)//�ڽӱ�ļӱ߲���
{
	nex[i] = fir[ u[i] ];
	fir[ u[i] ] = i;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;++i)//n-1��
	{
		//�����
		int i_1(i*2-1),i_2(i*2);
		scanf("%d%d",u+i_1,v+i_1);
		connect(i_1);
		//����
		u[i_2]=v[i_1];
		v[i_2]=u[i_1];
		connect(i_2);
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%d",w+i);
	}
	/*��Ϊ:������ͨͼ+ n-1����
	 *����:û�л�
	 *��Ϊ:�������Ϊ2
	 *����:��һ����Ϊ����,������ͨ�ĵ�֮��������Ϊ����
	 *     thisPoint_sum = ��� (w_all - w_one)*w_one
	 *                   = w_all * w_all - ��� w_one * w_one
	 */
	int w_all,sum_one,w_max1,w_max2;
	for(int i=1;i<=n;++i)
	{
		//����ýڵ�ֻ��һ����ͨ��,���õ���
		//w_max2 = 0 && w_all = sum_one
		w_all=0;
		sum_one=0;
		w_max1=0;//��һ��
		w_max2=0;//�ڶ���
		for(int p=fir[i];p;p=nex[p])
		{
			int now_v = v[p];

			w_all = (w_all + w[now_v])%Mo;
			sum_one = ( sum_one + ( w[now_v]*w[now_v] )%Mo )%Mo;

			if(w[now_v]>w_max1)
			{
				w_max1=w[now_v];
			}
			//else ����ʣ������ѡ�ڶ���
			else if(w[now_v]>=w_max2)// >= ��һ�� �� �ڶ��� һ����
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
