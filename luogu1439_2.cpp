#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 3e3 + 7;

int n;
int a[Maxn], b[Maxn];
int f[Maxn][Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a+i);
	for(int i = 1; i <= n; ++i) scanf("%d", b+i);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			if(a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
			else f[i][j] = max(f[i-1][j], f[i][j-1]);
		}
	printf("%d\n", f[n][n]);
	return 0;
}

