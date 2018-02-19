#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=16+2;
int m,n,sx,sy,ex,ey;
bool T[N][N],vis[N][N],flag;

void bfs(int x,int y)
{
	if(x==ex&&y==ey)
	{
		flag=1;
		return;
	}
	vis[x][y]=1;
	if(T[x-1][y]&&vis[x-1][y]==0)
		bfs(x-1,y);
	if(T[x+1][y]&&vis[x+1][y]==0)
		bfs(x+1,y);
	if(T[x][y-1]&&vis[x][y-1]==0)
		bfs(x,y-1);
	if(T[x][y+1]&&vis[x][y+1]==0)
		bfs(x,y+1);
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
		bfs(sx,sy);
		if(flag)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
