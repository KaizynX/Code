#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int Maxn = 2000;

int Case,n,ans;
int a[Maxn][Maxn],f[Maxn][Maxn];

inline int min3(int a,int b,int c)
{
	return min(a,min(b,c));
}

int main()
{
	scanf("%d",&Case);
	while(Case--)
	{
		memset(a,0,sizeof a);
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(a[i][j]==1)f[i][j]=0;
				else
				{
					f[i][j]=min3(f[i][j-1],f[i-1][j],f[i-1][j-1])+1;
					ans=max(ans,f[i][j]);
				}
			}
		}
		printf("%d\n",ans*ans);
	}
	return 0;
}
