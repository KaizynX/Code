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
//WA
#include <iostream>

using namespace std;
const int maxn=1009;
int n,bx,by,ex,ey,m[1009][1009];
bool a[1009][1009],u[1009][1009];

void bfs(int x,int y,int s)
{
	u[x][y]=1;
	if(x<0||y<0||x>=n||y>=n)return;
	if(s<m[x][y]||!m[x][y])m[x][y]=s;
	else if(s>=m[x][y])return;
	
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
	cout<<m[ex-1][ey-1]<<endl;
	return 0;
}
