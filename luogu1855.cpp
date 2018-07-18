#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn =  207;

int n, M, T;
int f[Maxn][Maxn];

int main()
{
	scanf("%d%d%d", &n, &M, &T);
	for(int i = 1, m, t; i <= n; ++i)
	{
		scanf("%d%d", &m, &t);
		for(int j = M; j >= m; --j)
			for(int k = T; k >= t; --k)
				f[j][k] = max(f[j][k], f[j-m][k-t] + 1);
	}
	printf("%d\n", f[M][T]);
	return 0;
}
