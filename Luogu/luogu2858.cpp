#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 2e3 + 7;

int n, ans;
int v[Maxn];
int f[Maxn][Maxn];
// f[l][r] take l from left and r from right 

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", v+i);
	for(int k = 1; k <= n; ++k)
		for(int l = 0, r; l <= k; ++l)
		{
			r = k - l;
			if(l) f[l][r] = max(f[l][r], f[l-1][r] + k * v[l]);
			if(r) f[l][r] = max(f[l][r], f[l][r-1] + k * v[n-r+1]);
			if(k == n) ans = max(ans, f[l][r]);
		}
	printf("%d\n", ans);
	return 0;
}
