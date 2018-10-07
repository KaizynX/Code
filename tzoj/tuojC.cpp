#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int Maxn = 256+5;

int T;
int h,w,t;
int a[Maxn][Maxn];

int main()
{
	int i,j,now;
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof a);
		scanf("%d%d%d",&h,&w,&t);
		for(i=1;i<=h;++i)
		{
			for(j=1;j<=w;++j)
			{
				scanf("%d",&now);
				if(now>=t)
					a[i][j]=255;
			}
		}
		for(i=1;i<=h;++i)
		{
			for(j=1;j<w;++j)
			{
				printf("%d ",a[i][j]);
			}
			printf("%d\n",a[i][j]);
		}
	}
	return 0;
}
