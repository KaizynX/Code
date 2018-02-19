#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn = 2*1e5+5;

int n;
int a[Maxn];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",a+i);
	}
	sort(a,a+n);

	int last,cnt;//cnt计数,last记录上一个
	last=a[0];
	cnt=1;
	printf("%d ",a[0]);
	for(int i=1;i<n;++i)
	{
		if(a[i]==last)cnt++;
		else
		{
			printf("%d\n%d ",cnt,a[i]);
			last=a[i];
			cnt=1;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
