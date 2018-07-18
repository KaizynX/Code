#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=16+2;
int m,n,sx,sy,ex,ey;
bool T[N][N],flag;
bool pd[N][N];

int main()
{
	int i,j,k;
	char c;
	scanf("%d",&m);
	while(m--)
	{
		memset(T,0,sizeof T);
		flag=0;
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
			{
				cin>>c;
				if(c=='.')
					T[i][j]=1;
				else if(c=='s')
					T[i][j]=1,sx=i,sy=j;
				else if(c=='e')
					T[i][j]=1,ex=i,ey=j;
			}
		pd[sx][sy]=1;
		for(k=0;k<n*n;++k)
		{
			if(flag)break;
			for(i=1;i<=n;++i)
			{
				if(flag)break;
				for(j=1;j<=n;++j)
				{
					if(T[i+1][j])
						pd[i][j]=pd[i][j]||pd[i+1][j];
					if(T[i-1][j])
						pd[i][j]=pd[i][j]||pd[i-1][j];
					if(T[i][j+1])
						pd[i][j]=pd[i][j]||pd[i][j+1];
					if(T[i][j-1])
						pd[i][j]=pd[i][j]||pd[i][j-1];
					if(i==ex&&j==ey&&pd[i][j])
					{
						flag=1;
						break;
					}
				}
			}
		}
		if(flag)
			printf("YES");
		else printf("NO");
	}
	return 0;
}
