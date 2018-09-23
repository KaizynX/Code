#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 2e4+7;

int n, sum, a[Maxn], b[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", a+i);
		sum += a[i];
	}
	if(n <= 3)
	{
		printf("%d\n", sum);
		return 0;
	}
	sum = a[1]+a[2];
	for(int i = 3, rest; i < n; ++i)
	{
		rest = b[i-1]+a[i-2];
		if(rest >= a[i]) b[i] = rest-a[i];
		else sum += a[i]-rest;
	}
	printf("%lld\n", 3ll*sum);
	return 0;
}
