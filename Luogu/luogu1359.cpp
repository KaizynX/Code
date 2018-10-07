#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 207;

int n;
int a[Maxn][Maxn];
int d[Maxn][Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
		for(int j = i + 1; j <= n; ++j)
			scanf("%d", &a[i][j]);
	for(int i = 2; i <= n; ++i) d[1][i] = a[1][i];
	for(int i = 2; i <= n; ++i)
		for(int j = 2; j < i; ++j)
			d[1][i] = min(d[1][i], d[1][j] + a[j][i]);
	printf("%d\n", d[1][n]);
	return 0;
}
