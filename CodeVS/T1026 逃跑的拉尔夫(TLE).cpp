#include <iostream>

using namespace std;
int r,c,n,map[52][52],d[1002][2];

bool judge(int x,int y)
{
	if(x<1||x>r||y<1||y>c||map[x][y]==0)return 0;
	else return 1;
}

void bfs(int x,int y,int num)
{
	if(num>n)
	{
		map[x][y]=2;
		return;
	}
	int cx=x+d[num][0],cy=y+d[num][1];
	while(judge(cx,cy))
	{ 
		bfs(cx,cy,num+1);
		cx+=d[num][0];
		cy+=d[num][1];
	}
}

int main()
{
	char a;
	string b;
	int lx,ly;
	cin>>r>>c;
	for(int i=1;i<=r;++i)
		for(int j=1;j<=c;++j)
		{
			cin>>a;
			if(a=='.')map[i][j]=1;
			else if(a=='*')
			{
				map[i][j]=1;
				lx=i;
				ly=j;
			} 
		}
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>b;
		if(b=="NORTH")d[i][0]=-1,d[i][1]=0;
		else if(b=="SOUTH")d[i][0]=1,d[i][1]=0;
		else if(b=="WEST")d[i][0]=0,d[i][1]=-1;
		else if(b=="EAST")d[i][0]=0,d[i][1]=1;	
	}
	bfs(lx,ly,1);
	for(int i=1;i<=r;++i)
	{
		for(int j=1;j<=c;++j)
		{
			if(map[i][j]==1)cout<<'.';
			else if(map[i][j]==0)cout<<'X';
			else if(map[i][j]==2)cout<<'*';
		}
		cout<<endl;
	}
	return 0;
}
