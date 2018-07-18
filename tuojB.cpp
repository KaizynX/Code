#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int T;
int m,s,n,ans;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&m,&s,&n);
		ans=s+(n%m);
		if(ans>m)ans-=m;
		printf("%d\n",ans);
	}
	return 0;
}
