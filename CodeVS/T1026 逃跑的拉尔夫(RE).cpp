//RE???
#include <iostream>
#include <cstdio>
#define NN 2505
#define N 55
using namespace std;
int r,c,n,map[N][N],d[1002][2],f1[NN][2];

bool judge(int x,int y)
{
	if(x<1||x>r||y<1||y>c||!map[x][y])return 0;
	else return 1;
}

void bfs(int num,int f[NN][2],int sum)
{
	int f2[NN][2],flag=0,cx,cy;
	for(int i=1;i<=sum;++i)
	{
		cx=f[i][0]+d[num][0];
		cy=f[i][1]+d[num][1];
		while(judge(cx,cy))
		{ 
			map[cx][cy]=num+1;
			f2[++flag][0]=cx;
			f2[flag][1]=cy;
			cx+=d[num][0];
			cy+=d[num][1];
		}
	}
	if(num==n)return;
	else bfs(num+1,f2,flag);
}

int main()
{
	char a;
	string b;
	int lx,ly;
	scanf("%d%d",&r,&c);
	a=getchar();
	for(int i=1;i<=r;++i)
	{
		for(int j=1;j<=c;++j)
		{
			a=getchar();
			if(a=='.')map[i][j]=1;
			else if(a=='*')
			{
				map[i][j]=1;
				lx=i;
				ly=j;
			}
		}
		a=getchar();
	}
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		cin>>b;
		if(b=="NORTH")d[i][0]=-1,d[i][1]=0;
		else if(b=="SOUTH")d[i][0]=1,d[i][1]=0;
		else if(b=="WEST")d[i][0]=0,d[i][1]=-1;
		else if(b=="EAST")d[i][0]=0,d[i][1]=1;	
	}
	f1[1][0]=lx;
	f1[1][1]=ly;
	bfs(1,f1,1);
	for(int i=1;i<=r;++i)
	{
		for(int j=1;j<=c;++j)
		{
			if(map[i][j]==n+1)printf("*");
			else if(map[i][j]==0)printf("X");
			else printf(".");
		}
		printf("\n");
	}
	return 0;
}
