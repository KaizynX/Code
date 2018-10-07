#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e5 + 7;

int n, a[Maxn], ans;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a+i);
	for(int i = 1, maxn; i <= n; ++i)
	{
		if(a[i] == 1)
		{
			ans += n-i+1;
			continue;
		}
		maxn = a[i];
		for(int j = i; j <= n; ++j)
		{
			if(a[j] > maxn) maxn = a[j];
			if(a[i] * a[j] <= maxn) ++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
