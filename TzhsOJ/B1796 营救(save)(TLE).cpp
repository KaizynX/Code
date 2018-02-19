/*//TLE
#include <iostream>

using namespace std;
int n,bx,by,ex,ey,ans=0x7fffffff;
bool a[1000][1000],u[1000][1000];

void bfs(int x,int y,int s)
{
	u[x][y]=1;
	if(x==ex-1&&y==ey-1)
	{
		ans=min(ans,s);
		return;
	}
	if(x<0||y<0||x>=n||y>=n)return;
	
	if(!a[x+1][y]&&!u[x+1][y])bfs(x+1,y,s+1);
	if(!a[x][y+1]&&!u[x][y+1])bfs(x,y+1,s+1);
	if(!a[x-1][y]&&!u[x-1][y])bfs(x-1,y,s+1);
	if(!a[x][y-1]&&!u[x][y-1])bfs(x,y-1,s+1);
	
	u[x][y]=0;
	return;
}

int main()
{
	char b;
	cin>>n;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
			cin>>b;
			if(b=='1')a[i][j]=1;
			else a[i][j]=0;
		}
	cin>>bx>>by>>ex>>ey;
	bfs(bx-1,by-1,0);
	cout<<ans<<endl;
	return 0;
}*/
//still TLE
#include <cstring>
#include <iostream>
using namespace std;
const int N=1009;
int n,bx,by,ex,ey,f[N][N],d[4][2]={-1,0,1,0,0,-1,0,1};
bool a[N][N];

void bfs(int x,int y,int s)
{
	f[x][y]=s;
	
	int cx,cy;
	for(int i=0;i<4;++i)
	{
		cx=x+d[i][0];
		cy=y+d[i][1];
		if(a[cx][cy]||s+1>=f[cx][cy]||cx<1||cx>n||cy<1||cy>n)
			continue;
		bfs(cx,cy,s+1);
	}
}

int main()
{
	char b;
	cin>>n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			cin>>b;
			if(b=='1')a[i][j]=1;
			//else a[i][j]=0;
		}
	memset(f,1,sizeof f);//f=max
	cin>>bx>>by>>ex>>ey;
	bfs(bx,by,0);
	cout<<f[ex][ey]<<endl;
	return 0;
}
