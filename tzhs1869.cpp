#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn = 50000+5;

int L,N,M,ans;
int l,r,mid;
int a[Maxn];

bool judge(int d)
{
	int cnt=0,now=1,last=0;
	while(now<N+1)
	{
		if(a[now]-a[last]<d)
		{
			cnt++;
		}
		else
		{
			last=now;
		}
		now++;
	}
	if(cnt>M)return 0;
	else return 1;
}

int main()
{
	scanf("%d%d%d",&L,&N,&M);
	for(int i=1;i<=N;++i)
	{
		scanf("%d",a+i);
	}
	a[N+1]=L;
	l=1;
	r=L;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(judge(mid)==1)
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
