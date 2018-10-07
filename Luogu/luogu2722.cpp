#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e4 + 7;
const int Maxm = 1e4 + 7;

int n, m;
int f[Maxm];

int main()
{
	scanf("%d%d", &m, &n);
	for(int i = 0, c, t; i < n; ++i)
	{
		scanf("%d%d", &c, &t);
		for(int v = t; v <= m; ++v)
			f[v] = max(f[v], f[v-t] + c);
	}
	printf("%d\n", f[m]);
	return 0;
}

