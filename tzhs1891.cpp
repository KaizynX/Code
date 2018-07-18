#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn = 200000;
const int Maxk = 50;
const int Maxp = 100;

int n,k,p,ans;
int col[Maxn+5],mon[Maxn+5];
int scol[Maxn+5][Maxk+5],smon[Maxn+5];
//scol[n][k] n个之前k色的总数
//smon[n] n个之前满足p的店的数量

inline void in();

inline void solve()
{
	int i,j,ncol;
	for(i=1;i<n;++i)
	{
		ncol=col[i];
		for(j=i+1;j<=n;++j)
		{
			if(ncol==col[j])
			{
				if(smon[j]-smon[i-1]>0)//i,j之间有满足的店
				{
					//则i与j之后任意一家同色的店都有满足的方案
					ans+=(scol[n][ncol]-scol[j-1][ncol]);
					break;
				}
			}
			//后面没有同色的店
			if(scol[n][ncol]==scol[j][ncol])break;
		}
	}
	printf("%d\n",ans);
}

int main()
{
	in();
	solve();
	return 0;
}

inline void in()
{
	scanf("%d%d%d",&n,&k,&p);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",col+i,mon+i);
		for(int j=0;j<k;++j)
		{
			scol[i][j]=scol[i-1][j];
		}
		scol[i][col[i]]++;
		smon[i]=smon[i-1];
		if(mon[i]<=p)smon[i]++;
	}
}
