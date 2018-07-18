#include <cstdio>
#include <iostream>
using namespace std;

const int Maxn = 20+5;
const int Maxx = 128+5;
const int Maxk = 1000000+5;
//x from 0 --- 128
int d,n,x,y,k,ans,ansk;
int a[Maxx][Maxx];
int s[Maxx][Maxx];
//s[x][y]表示[0,0]到[x,y]的公共场所数量

inline int cul(int bx,int by,int ex,int ey)//计算[bx,by],[ex,ey]之间的数量
{
	if(bx<1)bx=1;
	if(by<1)by=1;
	if(ex>129)ex=129;
	if(ey>129)ey=129;
	return s[ex][ey]-s[bx-1][ey]-s[ex][by-1]+s[bx-1][by-1];
}

int main()
{
	int now;
	scanf("%d%d",&d,&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&x,&y,&k);
		//0--128   +1   1--129
		x++;y++;
		a[x][y]=k;
	}
	for(x=1;x<=129;++x)
	{
		for(y=1;y<=129;++y)
		{
			s[x][y]=s[x-1][y]+s[x][y-1]-s[x-1][y-1]+a[x][y];
		}
	}
	for(x=1;x<=129;++x)
	{
		for(y=1;y<=129;++y)
		{
			now=cul(x-d,y-d,x+d,y+d);
			if(now>ans)
			{
				ans=now;
				ansk=1;
			}
			else if(now==ans)
			{
				ansk++;
			}
		}
	}
	printf("%d %d\n",ansk,ans);
	return 0;
}
