#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1007;
const int Maxt = 107;

int n, m, cnt;
int f[Maxn], a[Maxn], b[Maxn], c[Maxn], t[Maxt][Maxn];

int main()
{
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d%d", a+i, b+i, c+i);
		cnt = max(cnt, c[i]);
		int &cur = t[c[i]][0];
		t[c[i]][++cur] = i;
	}
	for(int i = 1; i <= cnt; ++i)
		for(int v = m; v >= 0; --v)
			for(int j = 1; j <= t[i][0]; ++j)
			{
				int &cur = t[i][j];
				if(v >= a[cur])
					f[v] = max(f[v], f[v - a[cur]] + b[cur]);
			}
	printf("%d\n", f[m]);
	return 0;
}
