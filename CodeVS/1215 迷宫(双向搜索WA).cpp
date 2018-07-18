#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=16+2;
int m,n,sx,sy,ex,ey;
bool T[N][N],vis[N][N],flag;
bool pd[N][N]; 

void bfs(int x,int y,int k)
{
	if(x+y==n+1)
	{
		if(k&&pd[x][y])
			flag=1;
		else if(k==0)
			pd[x][y]=1;
		return;
	}
	vis[x][y]=1;
	if(T[x-1][y]&&vis[x-1][y]==0)
		bfs(x-1,y,k);
	if(T[x+1][y]&&vis[x+1][y]==0)
		bfs(x+1,y,k);
	if(T[x][y-1]&&vis[x][y-1]==0)
		bfs(x,y-1,k);
	if(T[x][y+1]&&vis[x][y+1]==0)
		bfs(x,y+1,k);
	vis[x][y]=0;
}

int main()
{
	int i,j;
	char c;
	scanf("%d",&m);
	while(m--)
	{
		memset(T,0,sizeof T);
		memset(vis,0,sizeof vis);
		flag=0;
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
			{
				cin>>c;
				if(c=='.')
					T[i][j]=1;
				else if(c=='s')
					T[i][j]=1,sx=i,sy=j;
				else if(c=='e')
					T[i][j]=1,ex=i,ey=j;
			}
		bfs(sx,sy,0);
		bfs(ex,ey,1);
		if(flag)
			printf("YES\n");
		else printf("NO\n");
		for(i=1;i<=n;++i)
			printf("%d\n",pd[i][n-i+1]);
	}
	return 0;
}
