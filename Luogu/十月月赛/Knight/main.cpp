#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int N=50+2;
int pos[N][N],step[N][N],n,ex,ey;
bool G[N][N],vis[N][N];
queue <int> qx,qy;
int dog[8][2];

void C(int x,int y,int v)
{
	for(int i=1;i<=n;++i)
	{
		if(x-i>=1)G[x-i][y]+=v;
		if(x+i<=n)G[x+i][y]+=v;
		if(y-i>=1)G[x][y-i]+=v;
		if(y+i<=n)G[x][y+i]+=v;
	}
}

void B(int x,int y,int v)
{
	for(int i=1;i<=n;++i)
	{
		if(x-i>=1&&y-i>=1)
			G[x-i][y-i]+=v;
		if(x+i<=n&&y-i>=1)
			G[x+i][y-i]+=v;
		if(x-i>=1&&y+i<=n)
			G[x-i][y+i]+=v;
		if(x+i<=n&&y+i<=n)
			G[x+i][y+i]+=v;
	}
}

void Q(int x,int y,int v)
{
	C(x,y,v);
	B(x,y,v);
}

void X(int x,int y,int v)
{
	if(x+1<=n)G[x+1][y]+=v;
	if(x-1>=1)G[x-1][y]+=v;
	if(y+1<=n)G[x][y+1]+=v;
	if(y-1>=1)G[x][y-1]+=v;
	if(x-1>=1&&y-1>=1)
		G[x-1][y-1]+=v;
	if(x+1<=n&&y-1>=1)
		G[x+1][y-1]+=v;
	if(x-1>=1&&y+1<=n)
		G[x-1][y+1]+=v;
	if(x+1<=n&&y+1<=n)
		G[x+1][y+1]+=v;
}

void K(int x,int y,int v)
{
	if(x-1>=1)
	{
		if(x-2>=1)
		{
			if(y-1>=1)G[x-2][y-1]+=v;
			if(y+1<=n)G[x-2][y+1]+=v;
		}
		if(y-2>=1)G[x-1][y-2]+=v;
		if(y+2<=n)G[x-1][y+2]+=v;
	}
	if(x+1<=n)
	{
		if(x+2<=n)
		{
			if(y-1>=1)G[x+2][y-1]+=v;
			if(y+1<=n)G[x+2][y+1]+=v;
		}
		if(y-2>=1)G[x+1][y-2]+=v;
		if(y+2<=n)G[x+1][y+2]+=v;
	}
}

void P(int x,int y,int v)
{
	if(y+1<=n)
	{
		if(x-1>=1)G[x-1][y+1]+=v;
		if(x+1<=n)G[x+1][y+1]+=v;
	}
}

void chushihua()//side
{
	for(int i=0;i<=n+1;++i)
	{
		G[0][i]=1;
		G[i][0]=1;
		G[n+1][i]=1;
		G[i][n+1]=1;
	}
	vis[qx.front()][qy.front()]=1;
	dog[0][0]=-2;dog[0][1]=-1;
	dog[1][0]=-2;dog[1][1]=1;
	dog[2][0]=2;dog[2][1]=-1;
	dog[3][0]=2;dog[3][1]=1;
	dog[4][0]=-1;dog[4][1]=-2;
	dog[5][0]=-1;dog[5][1]=2;
	dog[6][0]=1;dog[6][1]=-2;
	dog[7][0]=1;dog[7][1]=2;
}

void release(int x,int y,char c)
{
	if(c=='C')
		pos[x][y]='C',C(x,y,-1);
	else if(c=='K')
		pos[x][y]='K',K(x,y,-1);
	else if(c=='B')
		pos[x][y]='B',B(x,y,-1);
	else if(c=='Q')
		pos[x][y]='Q',Q(x,y,-1);
	else if(c=='X')
		pos[x][y]='X',X(x,y,-1);
	else if(c=='P')
		pos[x][y]='P',P(x,y,-1);
}

int dfs()
{
	int x,y,nx,ny;
	while(!qx.empty())
	{
		x=qx.front();
		y=qy.front();
		qx.pop();
		qy.pop();
		//
		for(int i=0;i<8;++i)
        {
            nx=x+dog[i][0];
            ny=y+dog[i][1];
            if(nx<1||ny<1||nx>n||ny>n)continue;
            if(!G[nx][ny]&&!vis[nx][ny])
            {
                if(pos[nx][ny])
                    release(nx,ny,pos[nx][ny]);
                step[nx][ny]=step[x][y]+1;
                vis[nx][ny]=1;
                if(nx==ex&&ny==ey)
                    return step[nx][ny];
                qx.push(nx);
                qy.push(ny);
            }
        }
	}
	return -1;
}

int main()
{
	scanf("%d",&n);
	int i,j;
	char c;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
		{
			cin>>c;
			if(c=='.')continue;
			else if(c=='C')
				pos[i][j]='C',C(i,j,1);
			else if(c=='K')
				pos[i][j]='K',K(i,j,1);
			else if(c=='B')
				pos[i][j]='B',B(i,j,1);
			else if(c=='Q')
				pos[i][j]='Q',Q(i,j,1);
			else if(c=='X')
				pos[i][j]='X',X(i,j,1),ex=i,ey=j;
			else if(c=='P')
				pos[i][j]='P',P(i,j,1);
			else if(c=='O')
				qx.push(i),qy.push(j);
		}
	chushihua();
	printf("%d\n",dfs());
	return 0;
}
