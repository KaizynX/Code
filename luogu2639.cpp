#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 500 + 7;
const int Maxm = 45000 + 7;

int n, m;
int f[Maxm];

int main()
{
	scanf("%d%d", &m, &n);
	for(int i = 0, tmp; i < n; ++i)
	{
		scanf("%d", &tmp);
		for(int v = m; v >= tmp; --v)
			f[v] = max(f[v], f[v-tmp] + tmp);
	}
	printf("%d\n", f[m]);
	return 0;
}
