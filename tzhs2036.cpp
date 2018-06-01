#include <cstdio>
#include <iostream>
#define LL long long 

using namespace std;

const int Maxn = 100000+5;

int n,k,a[Maxn];
LL s[Maxn],ans,now;

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=k;++i)
	{
		now+=a[i]*i;
	}
	ans=now;
	for(int i=k+1;i<=n;++i)
	{
		now-=s[i-1]-s[i-k-1];
		now+=a[i]*k;
		if(now>ans)ans=now;
	}
	printf("%lld",ans);
	return 0;
}
