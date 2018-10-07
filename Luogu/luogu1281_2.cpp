#include <cstdio>
#include <iostream>
// #define DEBUG

using namespace std;

const int Maxn = 510;
const int INF = 0x3f3f3f3f;

int n, k;
int a[Maxn], s[Maxn];
int f[Maxn][Maxn];

void print(int cur, int t)
{
	int i = t, cnt = 0;
	while(i && (cnt += a[i]) <= f[k][n]) i--;
	if(cur > 1) print(cur-1, i);
	printf("%d %d\n", i+1, t);
}

int main()
{
	scanf("%d%d", &n, &k);
	if(n == 0) return 0;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", a+i);
		s[i] = s[i-1]+a[i];
	}
	for(int i = 1; i <= n; ++i)
		f[1][i] = s[i];
	for(int r = 2; r <= k; ++r)
		for(int i = r; i <= n; ++i)
		{
			f[r][i] = INF;
			for(int j = r-1; j < i; ++j)
				f[r][i] = min(f[r][i], max(f[r-1][j], s[i]-s[j]));
#ifdef DEBUG
			printf("%d %d %d %d\n", r, i, f[r][i], d[r][i]);
#endif
		}
#ifdef DEBUG
	printf("%d\n", f[k][n]);
#endif
	print(k, n);
	return 0;
}
