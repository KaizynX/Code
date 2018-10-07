#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 3402 + 7;
const int Maxm = 12880 + 7;

int n, m;
int w[Maxn], d[Maxn];
int f[Maxm];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d%d", w+i, d+i);
	for(int i = 1; i <= n; ++i)
		for(int v = m; v >= w[i]; --v)
			f[v] = max(f[v], f[v-w[i]] + d[i]);
	printf("%d\n", f[m]);
	return 0;
}
