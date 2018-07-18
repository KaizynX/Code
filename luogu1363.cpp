#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int Maxn = 1500+5;
const int Maxq = Maxn*Maxn;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
// WA TLE
int n,m,bx,by;
bool flag;
bool p[Maxn][Maxn],vis[Maxn*3][Maxn*3];

void bfs(int x,int y)
{
	if(flag==1)return;
	if(x<0 || x>n*3 || y<0 || y>m*3)
	{
		flag=1;
		return;
	}

	int nx,ny;
	vis[x][y]=1;
	for(int i=0;i<4;++i)
	{
		nx=x+dx[i];
		ny=y+dy[i];
		if(p[nx%n][ny%m]==0)
			continue;
		if(vis[nx][ny]==1)
			continue;
		bfs(nx,ny);
	}
	vis[x][y]=0;
}

int main()
{
	char c;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		//memset(p,0,sizeof p);
		memset(vis,0,sizeof vis);
		flag=0;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				cin>>c;
				if(c=='.')
					p[i][j]=1;
				else if(c=='#')
					p[i][j]=0;
				else if(c=='S')
				{
					bx=i;
					by=j;
					p[i][j]=1;
				}
			}
		}
		bfs(bx+n,by+m);
		if(flag==1)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
