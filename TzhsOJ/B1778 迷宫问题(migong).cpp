#include <iostream>

using namespace std;
bool a[10][10],u[10][10];
int ans=0,n;

void solve(int x,int y)
{
	u[x][y]=1;
	if(x==0&&y==n-1)
	{
		ans++;
		u[x][y]=0;
		return;
	}
	if(x>=n||y>=n||x<0||y<0)return;
	
	if(!a[x+1][y]&&!u[x+1][y])solve(x+1,y);
	if(!a[x][y+1]&&!u[x][y+1])solve(x,y+1);
	if(!a[x+1][y+1]&&!u[x+1][y+1])solve(x+1,y+1);
	if(!a[x+1][y-1]&&!u[x+1][y-1])solve(x+1,y-1);
	if(!a[x-1][y+1]&&!u[x-1][y+1])solve(x-1,y+1);
	if(!a[x-1][y]&&!u[x-1][y])solve(x-1,y);
	if(!a[x][y-1]&&!u[x][y-1])solve(x,y-1);
	if(!a[x-1][y-1]&&!u[x-1][y-1])solve(x-1,y-1);
	
	u[x][y]=0;
	return;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>a[i][j];
	solve(0,0);
	cout<<ans<<endl;
	return 0;
}
