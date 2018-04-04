#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n,k;

int main()
{
	long long cnt=1;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i)
	{
		printf("%lld ",cnt);
		cnt*=n;
	}
	return 0;
}
