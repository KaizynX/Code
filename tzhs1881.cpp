#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn = 100000+5;

int n,ans;
int a[Maxn],f[Maxn];

int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",a+i);
	}
	for(i=1;i<=n;++i)
	{
		if(a[i]>a[i-1])
		{
			ans+=a[i]-a[i-1];
		}
	}
	printf("%d\n",ans);
	return 0;
}
