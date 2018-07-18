#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn = 5000+5;

struct farm
{
	int s,t;
	bool operator < (const farm &b)const
	{
		return s<b.s;
	}
}a[Maxn];

int n;

int main()
{
	int tail,start,ans1,ans2;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&a[i].s,&a[i].t);
	}
	sort(a+1,a+1+n);
	//init
	start=a[1].s;
	tail=a[1].t;
	ans1=tail-start;
	ans2=0;
	for(int i=2;i<=n;++i)
	{
		if(a[i].s>tail)
		{
			ans1=max(ans1,tail-start);
			ans2=max(ans2,a[i].s-tail);
			start=a[i].s;
		}
		tail=max(tail,a[i].t);
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}
