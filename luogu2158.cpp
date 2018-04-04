#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn = 40000+5;
int f[Maxn],n;
//莫比乌斯反演 ? 欧拉函数
int main()
{
	scanf("%d",&n);
	n--;
	for(int i=n;i>0;--i)
	{
		f[i]=(n/i)*(n/i);
		for(int j=2;i*j<=n;++j)
		{
			f[i]-=f[i*j];
		}
	}
	printf("%d",f[1]+2);
	return 0;
}
