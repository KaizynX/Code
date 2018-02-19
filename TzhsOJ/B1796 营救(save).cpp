#include <iostream>
#include <cstring>
using namespace std;
const int N=1009;
int n,bx,by,ex,ey,d[4][2]={-1,0,1,0,0,-1,0,1};
bool a[N][N];

struct map
{
	int x,y,s;
}m[N*N];

int main()
{
	char b;
	cin>>n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			cin>>b;
			if(b=='1')a[i][j]=1;
		}
	cin>>bx>>by>>ex>>ey;
	
	int head=1,tail=1;
	int cx,cy;
	m[head].x=bx;m[head].y=by;
	while(head<=tail)
	{
		for(int i=0;i<4;++i)
		{
			cx=m[head].x+d[i][0];
			cy=m[head].y+d[i][1];
			if(cx<1||cy<1||cx>n||cy>n||a[cx][cy])
				continue;
			tail++;
			a[cx][cy]=1;//visited
			m[tail].x=cx;m[tail].y=cy;
			m[tail].s=m[head].s+1;
			if(cx==ex&&cy==ey)//find
			{
				cout<<m[tail].s<<endl;
				return 0;
			}
		}
		head++;
	}
	return 0;
}
