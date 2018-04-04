#include <cstdio>
#include <iostream>
#define LL long long 
using namespace std;
// up right down left
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
const int Maxr = 2000+5;
// Maxn = 10^18
int M[Maxr][Maxr];
LL r,c,bx,by,ex,ey,ed,n;

int main()
{
	LL nx,ny,nd,now,sum;
	cin>>r>>c>>bx>>by>>n;
	bx--;by--;//start from 0
	nx=bx;ny=by;nd=0;//turn up
	for(LL i=1;i<=n;++i)
	{
		nx=(nx+dx[nd]*(i%r))%r;
		ny=(ny+dy[nd]*(i%c))%c;
		nd=(nd+1)%4;
	}
	ex=nx;ey=ny;ed=nd-1;//
	nd=(nd+2)%4;
	now=0;sum=r*c;
	while(now<sum)
	{
		nx=(nx+dx[nd]*(i%r))%r;
		ny=(ny+dy[nd]*(i%c))%c;
		nd=(nd-1)%4;
	}
	printf("%lld %lld\n",ex,ey);
	return 0;
}
