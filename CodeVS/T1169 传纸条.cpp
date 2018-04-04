#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=52;
int m,n,map[N][N],f[N][N][N][N];

int max(int a, int b, int c, int d) {  
    if (a < b) a = b;  
    if (a < c) a = c;  
    if (a < d) a = d;  
    return a;  
}  

int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&map[i][j]);
	int x1,y1,x2,y2;
	for(x1=1;x1<=m;++x1)
		for(y1=1;y1<=n;++y1)
			for(x2=1;x2<=m;++x2)
			{
				if(x1+y1-x2>0)
					y2=x1+y1-x2;
				else continue;
				f[x1][y1][x2][y2]=max(f[x1-1][y1][x2-1][y2],
									f[x1-1][y1][x2][y2-1],
									f[x1][y1-1][x2-1][y2],
									f[x1][y1-1][x2][y2-1])
									+map[x1][y1]+map[x2][y2];
				if(x1==x2&&y1==y2)
					f[x1][y1][x2][y2]-=map[x1][y1];
			}
	printf("%d\n",f[m][n][m][n]);
	return 0;
}
