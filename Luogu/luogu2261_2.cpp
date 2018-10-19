#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	/*
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
		ans += k%i;
	printf("%lld\n", ans);
	*/
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		int ans = 0;
		printf("k=%d:", i);
		for(int j = 1; j <= n; ++j)
			printf("%d ", (ans += i%j));
		putchar('\n');
	}
	return 0;
}
