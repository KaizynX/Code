#include <iostream>

using namespace std;
const int maxn = 105;

int n,p,w[maxn][maxn];
struct node
{
	int c,u,in;
}a[maxn];


int main()
{
	int i,x,y,judge1=0;
	int flag,judge2;
	cin>>n>>p;
	for(i=1;i<=n;++i)
		cin>>a[i].c>>a[i].u;
	for(i=1;i<=p;++i)
	{
		cin>>x>>y;
		cin>>w[x][y];
	}
	
	while(judge1!=n)
	{
		judge1=0;
		for(i=1;i<=n;++i)
			if(a[i].c!=0)
			{
				for(int j=1;j<=n;++j)
					if(w[i][j]!=0)
					{
						;
					}
					else judge2++;
				if(judge2==n)judge1++;
			}
			else judge1++;
	}
	
	return 0;
}
