#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn = 39+5;

int n,m[Maxn][Maxn];
//行x 列y
int main()
{
	int nx,ny,lx,ly;
	scanf("%d",&n);
	lx=1;
	ly=n/2+1;
	m[lx][ly]=1;
	for(int i=2;i<=n*n;++i)
	{
		if(lx==1 && ly!=n)
		{
			nx=n;
			ny=ly+1;
			m[nx][ny]=i;
		}
		if(ly==n && lx!=1)
		{
			ny=1;
			nx=lx-1;
			m[nx][ny]=i;
		}
		if(lx==1 && ly==n)
		{
			nx=lx+1;
			ny=ly;
			m[nx][ny]=i;
		}
		if(lx!=1 && ly!=n)
		{
			if(m[nx-1][ny+1]==0)//右上方
			{
				nx=lx-1;
				ny=ly+1;
				m[nx][ny]=i;
			}
			else//正下方
			{
				nx=lx+1;
				ny=ly;
				m[nx][ny]=i;
			}
		}
		lx=nx;
		ly=ny;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<n;++j)
		{
			printf("%d ",m[i][j]);
		}
		printf("%d\n",m[i][n]);
	}
	return 0;
}
