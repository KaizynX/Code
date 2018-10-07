#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn = 100+5;

int n,m,ans;
int a[Maxn];
int s[Maxn];

int main()
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		ans=max(ans,a[i]);
		s[i]=s[i-1]+a[i];
	}
	for(int l=2;l<=m;++l)
	{
		for(i=l;i<=n;++i)
		{
			ans=max(ans,s[i]-s[i-l]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
