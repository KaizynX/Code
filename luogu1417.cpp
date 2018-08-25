#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 60;
const int Maxt = 1e5+7;

int T, n, res;
int dp[Maxt];

struct Food
{
	int a, b, c;
	bool operator < (const Food &nex) const
	{
		return b*nex.c > c*nex.b;
	}
} f[Maxn];

int main()
{
	scanf("%d%d", &T, &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &f[i].a);
	for(int i = 1; i <= n; ++i) scanf("%d", &f[i].b);
	for(int i = 1; i <= n; ++i) scanf("%d", &f[i].c);
	sort(f+1, f+n+1);
	for(int i = 1; i <= n; ++i)
		for(int j = min(T, f[i].a/f[i].b); j >= f[i].c; --j)
			dp[j] = max(dp[j], dp[j-f[i].c]+f[i].a-j*f[i].b);
	for(int i = 1; i <= T; ++i) res = max(res, dp[i]);
	printf("%d\n", res);
	return 0;
}
