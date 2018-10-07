#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int Maxn = 107;
const int Maxt = 25;
const int Maxd = 2e3+7;

int n, D;
int dp[Maxd];

struct Portal
{
	int t, d, c;
	bool operator < (const Portal &b) const
	{
		return d < b.d;
	}
} a[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d%d", &a[i].t, &a[i].d, &a[i].c);
		D = max(D, a[i].d);
	}
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; ++i)
	{
		// the time finish it
		for(int j = a[i].d-1; j >= a[i].t; --j)
			dp[j] = max(dp[j], dp[j-a[i].t]+a[i].c);
		for(int j = a[i].d; j < D; ++j)
			dp[j] = max(dp[j], dp[j-1]);
#ifdef DEBUG
		for(int j = 1; j < D; ++j)
			printf("%d ", dp[j]);
		putchar('\n');
#endif
	}
	printf("%d\n", dp[D-1]);
	return 0;
}
