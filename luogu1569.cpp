#include <iostream>
#include <cstdio>
#define DEBUG

using namespace std;

const int Maxn = 1007;
const int INF = 0x3f3f3f3f;

int n;
int s[Maxn];
int f[Maxn][Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1, a; i <= n; ++i)
	{
		scanf("%d", &a);
		s[i] = s[i-1] + a;
		f[i][i] = (a >= 0 ? 1 : -INF);
	}
	for(int k = 2; k <= n; ++k)
		for(int l = 1, r; l+k-1 <= n; ++l)
		{
			r = l + k - 1;
			f[l][r] = (s[r]-s[l-1] >= 0 ? 1 : -INF);
			for(int i = l; i < r; ++i)
				f[l][r] = max(f[l][r], f[l][i] + f[i+1][r]);
#ifdef DEBUG
			printf("%d %d %d\n", l, r, f[l][r]);
#endif
		}
	if(f[1][n] <= 0) puts("Impossible");
	else printf("%d\n", f[1][n]);
	return 0;
}
