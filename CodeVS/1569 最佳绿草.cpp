#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=100+2;
int r,c,ans;
bool G[N][N],vis[N][N];

void bfs(int x,int y)
{
	vis[x][y]=1;
	if(G[x+1][y]&&vis[x+1][y]==0)
		bfs(x+1,y);
	if(G[x-1][y]&&vis[x-1][y]==0)
		bfs(x-1,y);
	if(G[x][y+1]&&vis[x][y+1]==0)
		bfs(x,y+1);
	if(G[x][y-1]&&vis[x][y-1]==0)
		bfs(x,y-1);
}

int main()
{
	int i,j;
	char a;
	scanf("%d%d",&r,&c);
	for(i=1;i<=r;++i)
		for(j=1;j<=c;++j)
		{
			cin>>a;
			if(a=='#')
				G[i][j]=1;	
		}
	for(i=1;i<=r;++i)
		for(j=1;j<=c;++j)
			if(G[i][j]&&vis[i][j]==0)
			{
				bfs(i,j);
				ans++;
			}
	printf("%d\n",ans);
	return 0;
}
