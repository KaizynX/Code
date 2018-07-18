#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn = 50000;

int L,n,m,ans;
int d[Maxn+5];
int l,r,mid;

bool pd(int len)
{
	int now=1,last=0;
	int need=0;
	while(now<n+1)
	{
		if(d[now]-d[last]<len)//can jump
		{
			need++;//move the stone
		}
		else //can't jump through
		{
			last=now;//jump to it
		}
		now++;
	}
	if(need>m)return 0;
	else return 1;
}

int main()
{
	scanf("%d%d%d",&L,&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",d+i);
	}
	//d[0]=0;
	d[n+1]=L;
	l=1;r=L;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(pd(mid)==1)//it's ok
		{
			ans=mid;
			l=mid+1;//find smaller
		}
		else //need bigger
		{
			r=mid-1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
