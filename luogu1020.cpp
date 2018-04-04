#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int Maxn = 100000+5;

int a[Maxn],n;
int up[Maxn],dn[Maxn],pu,pd;

int main()
{
	int p;
	while(scanf("%d",&a[++n])==1);
	n--;
	up[1]=a[1];pu=1;
	dn[1]=a[1];pd=1;
	for(int i=2;i<=n;++i)
	{
		p=upper_bound(up+1,up+1+pu,a[i], greater<int>() )-up;
		up[p]=a[i];
		if(p>pu)pu=p;
	}
	for(int i=2;i<=n;++i)
	{
		p=lower_bound(dn+1,dn+1+pd,a[i])-dn;
		dn[p]=a[i];
		if(p>pd)pd=p;
	}
	printf("%d\n%d\n",pu,pd);
	return 0;
}
