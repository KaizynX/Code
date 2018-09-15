#include <cstdio>
#include <iostream>

using namespace std;

const int Mo = 2015;

const int Maxn = 1e3+7;

int n, k;
int f[Maxn][Maxn];

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
	{
		f[i][0] = f[i][i-1] = 1;
		for(int j = 1; j <= min(k, i-2); ++j)
			f[i][j] = (f[i-1][j]*(j+1)%Mo + f[i-1][j-1]*(i-j)%Mo)%Mo;
	}
	printf("%d\n", f[n][k]);
	return 0;
}
