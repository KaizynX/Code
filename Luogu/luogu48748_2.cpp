#include <bits/stdc++.h>

using namespace std;

const int Maxn = 507;

int n, m;
int a[Maxn][Maxn], b[Maxn][Maxn];

inline void init();
inline void print();

inline void operate(int x, int y, int r, int z)
{
	for(int i = x-r; i <= x+r; ++i)
		for(int j = y-r; j <= y+r; ++j)
			b[i][j] = a[i][j];
	for(int i = -r, I, J; i <= r; ++i)
		for(int j = -r; j <= r; ++j)
		{
			if(z) I = j, J = -i;
			else I = -j, J = i;
			a[x+i][y+j] = b[x+I][y+J];
		}
}

int main()
{
	int x, y, r, z;
	scanf("%d%d", &n, &m);
	init();
	while(m--)
	{
		scanf("%d%d%d%d", &x, &y, &r, &z);
		operate(x, y, r, z);
	}
	print();
	return 0;
}

inline void print()
{
	for(int i = 1; i <= n; ++i, putchar('\n'))
		for(int j = 1; j <= n; ++j)
			printf("%d ", a[i][j]);
}

inline void init()
{
	for(int i = 1, cur = 0; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			a[i][j] = ++cur;
}
