#include <cstdio>
#include <iostream>
#define LL long long 
using namespace std;
const int Maxn = 20+5;

int hx,hy,tx,ty;
LL f[Maxn][Maxn];
bool a[Maxn][Maxn];

void house(int x,int y)
{
	a[x][y]=1;
	a[x+1][y+2]=1;
	a[x+1][y-2]=1;
	a[x-1][y+2]=1;
	a[x-1][y-2]=1;
	a[x+2][y+1]=1;
	a[x+2][y-1]=1;
	a[x-2][y+1]=1;
	a[x-2][y-1]=1;
}

int main()
{
	scanf("%d%d%d%d",&tx,&ty,&hx,&hy);
	tx++;ty++;
	hx++;hy++;
	f[1][1]=1;
	house(hx,hy);
	for(int i=1;i<=tx;++i)
	{
		for(int j=1;j<=ty;++j)
		{
			if(a[i][j]==1)f[i][j]=0;
			else f[i][j]+=f[i-1][j]+f[i][j-1];
		}
	}
	printf("%lld\n",f[tx][ty]);
	return 0;
}
