#include <iostream>
#include <cstdio>
#include <algorithm>
#define DEBUG

using namespace std;

const int Maxn = 2e3 + 7;
const int INF = 4e5;

int n, ans = -INF;
int a[Maxn], b[Maxn];
int f[Maxn][Maxn];

inline int dif(int i, int j)
{
	return b[i] == a[j] ? 0 : (b[i] > a[j] ? -200 : 200);
	/*
	if(b[i] == a[j]) return 0;
	else if(b[i] > a[j]) return -200;
	else return 200;
	*/
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a+i);
	for(int i = 1; i <= n; ++i) scanf("%d", b+i);
	sort(a+1, a+n+1); reverse(a+1, a+n+1);
	sort(b+1, b+n+1); reverse(b+1, b+n+1);
	for(int k = 1; k <= n; ++k)
	{
		for(int l = 0, r; l <= k; ++l)
		{
			r = k - l;
			f[l][r] = -INF;
			// f[i][j] = max(f[i-1][j] + now, f[i][j-1] + now);
			if(l - 1 >= 0) f[l][r] = max(f[l][r], f[l-1][r] + dif(k, l));
			if(r - 1 >= 0) f[l][r] = max(f[l][r], f[l][r-1] + dif(k, n-r+1));
#ifdef DEBUG
			printf("%d %d %d\n", l, r, f[l][r]);
#endif
		}
	}
	for(int i = 0; i <= n; ++i) ans = max(ans, f[i][n-i]);
	printf("%d\n", ans);
	return 0;
}
