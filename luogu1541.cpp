#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn = 350+5;
//const int Maxm = 120+5;//总张数
const int Maxb = 40+5;//单种最大个数

int n,m;
int a[Maxn],b[5];
//a记录该点的分值,b记录卡片数量
int f[Maxb][Maxb][Maxb][Maxb];

int main()
{
	//读入
	scanf("%d%d",&n,&m);
	//从1~n,故等效于0~n-1
	for(int i=0;i<n;++i)
	{
		scanf("%d",a+i);
	}
	for(int i=0;i<m;++i)
	{
		int tmp;
		scanf("%d",&tmp);
		b[tmp]++;
	}

	//DP
	//最坏情况O(30^4)
	for(int b1=0;b1<=b[1];++b1)
	{
		for(int b2=0;b2<=b[2];++b2)
		{
			for(int b3=0;b3<=b[3];++b3)
			{
				for(int b4=0;b4<=b[4];++b4)
				{
					//寻找之前的最优方案
					int &tmp=f[b1][b2][b3][b4];
					if(b1>=1)tmp=max(tmp,f[b1-1][b2][b3][b4]);
					if(b2>=1)tmp=max(tmp,f[b1][b2-1][b3][b4]);
					if(b3>=1)tmp=max(tmp,f[b1][b2][b3-1][b4]);
					if(b4>=1)tmp=max(tmp,f[b1][b2][b3][b4-1]);
					//加上这一步的分数
					tmp+=a[b1+b2*2+b3*3+b4*4];
					//debug
					//printf("%d %d %d %d %d\n",b1,b2,b3,b4,tmp);
				}
			}
		}
	}
	printf("%d",f[b[1]][b[2]][b[3]][b[4]]);
	return 0;
}
