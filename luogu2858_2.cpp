#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 2e3 + 7;

int n;
int s[Maxn];
int f[Maxn][Maxn];
// f[l][r] range[l, r] 

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
	{
		scanf("%d", &f[i][i]);
		s[i] = s[i-1] + f[i][i];
	}
	for(int k = 2; k <= n; ++k)
		for(int l = 1, r; l+k-1 <= n; ++l)
		{
			r = l + k - 1;
			f[l][r] = max(f[l+1][r], f[l][r-1]) + s[r] - s[l-1];
		}
	printf("%d\n", f[1][n]);
	return 0;
}
