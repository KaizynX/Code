#include <cstdio>
#include <iostream>

using namespace std;

const int maxn = 1000000+5;

int n,x,ans;

void f(int i)
{
	while(i)
	{
		if(i%10==x)
			ans++;
		i/=10;
	}
}

int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;++i)
	{
		f(i);
	}
	printf("%d",ans);
	return 0;
}
