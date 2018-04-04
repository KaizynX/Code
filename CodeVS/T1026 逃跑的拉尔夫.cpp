#include <iostream>
#include <cstdio>
#define MAXN 10000000
#define N 55
#define NN 1001
using namespace std;
int r,c,n,map[N][N],d[NN][2];
bool pd[N][N][NN];
struct node
{
	int x,y,s;
}f[MAXN];

bool judge(int x,int y,int dp)
{
	if(x<1||x>r||y<1||y>c||!map[x][y]||pd[x][y][dp])
		return 0;
	else return 1;
}

int main()
{
	freopen("test.in","r",stdin);//
	char a;
	string b;
	int lx,ly;
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;++i)
		for(int j=1;j<=c;++j)
		{
			cin>>a;
			if(a=='.')map[i][j]=1;
			else if(a=='*')
			{
				map[i][j]=1;
				lx=i;ly=j;
			}
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
	//bfs
	int head=1,tail=1;
	f[head].x=lx;f[head].y=ly;
	while(head<=tail)
	{
		int dp=f[head].s+1;
		int cx=f[head].x+d[dp][0],cy=f[head].y+d[dp][1];
		while(judge(cx,cy,dp))
		{
			pd[cx][cy][dp]=1;
			tail++;
			f[tail].x=cx;
			f[tail].y=cy;
			f[tail].s=dp;
			
			cx+=d[dp][0];cy+=d[dp][1];
		}
		head++;
	}
	//print
	for(int i=1;i<=r;++i)
	{
		for(int j=1;j<=c;++j)
		{
			if(pd[i][j][n])printf("*");
			else if(map[i][j]==0)printf("X");
			else printf(".");
		}
		printf("\n");
	}
	//debug
	for(int i=1;i<=r;++i)
	{
		for(int j=1;j<=c;++j)
		{
			printf("%d",map[i][j]);
		}
		printf("\n");
	}
	cout<<pd[3][5][1]<<" "<<judge(3,5,1);
	return 0;
}
