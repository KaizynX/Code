#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 107;

int n, ave, ans;
int a[Maxn];

int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d",a+i);
		ave += a[i];
	}
	ave /= n;
	for(int i = 1; i <= n; ++i)
	{
		if(a[i] != ave)
		{
			a[i+1] += a[i] - ave;
			++ans;
		}
	}
	printf("%d\n",ans);
	return 0;
}
