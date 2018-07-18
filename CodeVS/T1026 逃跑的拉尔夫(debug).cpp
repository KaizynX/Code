#include <iostream>

using namespace std;
int r,c,n,map[52][52],d[1002][2],f1[1][2];

bool judge(int x,int y)
{
	if(x<1||x>r||y<1||y>c||map[x][y]==0)return 0;
	else return 1;
}

void bfs(int num,int f[][2])
{
	if(num>n)return;
	int f2[2500][2],flag=-1;
	for(int i=0;i<num;++i)
	{
		int cx=f[num][0]+d[num][0],cy=f[num][1]+d[num][1];
		while(judge(cx,cy))
		{ 
			map[cx][cy]=num+1;
			f2[++flag][0]=cx;
			f2[flag][1]=cy;
			cx+=d[num][0];
			cy+=d[num][1];
		}
	}
	return bfs(num+1,f);
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
	f1[0][0]=lx;
	f1[0][1]=ly;
	bfs(1,f1);
	for(int i=1;i<=r;++i)
	{
		for(int j=1;j<=c;++j)
		{
			if(map[i][j]==n+1)cout<<'*';
			else if(map[i][j]==0)cout<<'X';
			else cout<<'.';
		}
		cout<<endl;
	}
	return 0;
}
