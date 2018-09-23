#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 2e4+7;

int n, sum, sta, a[Maxn], b[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", a+i);
		sum += a[i];
		if(a[i] < a[sta]) sta = i;
	}
	if(n <= 3)
	{
		printf("%d\n", sum);
		return 0;
	}
	sum = a[sta]+a[(sta+1)%n];
	for(int i = 2, rest, now; i < n; ++i)
	{
		now = (sta+i)%n;
		rest = b[(now-1+n)%n]+a[(now-2+n)%n];
		if(rest >= a[now]) b[now] = rest-a[now];
		else sum += a[now]-rest;
	}
	printf("%lld\n", 3ll*sum);
	return 0;
}
