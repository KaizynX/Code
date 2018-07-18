#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define DEBUG

using namespace std;

const int Maxn = 1e3 + 7;

int n, m;
int f[2][Maxn];

struct Node
{
	int a, b, c;
	bool operator < (const Node &b) const
	{
		return c < b.c;
	}
} a[Maxn];

#ifdef DEBUG
inline void print()
{
	for(int i = 1; i <= m; ++i) printf("%d ", f[0][i]); putchar('\n');
	for(int i = 1; i <= m; ++i) printf("%d ", f[1][i]); putchar('\n');
	putchar('\n');
}
#endif

int main()
{
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; ++i) scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
	sort(a, a+n);
	int cur = 0;
	for(int i = 0; i < n; ++i)
	{
		if(i && a[i].c != a[i-1].c)
		{
			cur ^= 1;
			memcpy(f[cur], f[cur^1], sizeof(int)*(m+1));
		}
		for(int v = a[i].a; v <= m; ++v)
			f[cur][v] = max(f[cur][v], f[cur^1][v-a[i].a] + a[i].b);
#ifdef DEBUG
		print();
#endif
	}
	printf("%d\n",f[cur][m]);
	return 0;
}
