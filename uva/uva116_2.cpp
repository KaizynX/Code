#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 107;
const int Maxm = 12;
const int INF = 0x7fffffff;

int n, m, ans, fir;
int a[Maxm][Maxn], f[Maxm][Maxn], nex[Maxm][Maxn];

int main()
{
	while(scanf("%d%d", &m, &n) == 2)
	{
		ans = INF;
		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j)
				scanf("%d", &a[i][j]);
		for(int j = n-1; j >= 0; --j)
			for(int i = 0; i < m; ++i)
			{
				if(j == n-1) { f[i][j] = a[i][j]; continue; }
				f[i][j] = INF;
				int rows[3]= { i-1, i, i+1 };
				if(i == 0) rows[0] = m-1;
				if(i == m-1) rows[2] = 0;
				sort(rows, rows+3);
				for(int k = 0; k < 3; ++k)
				{
					if(f[rows[k]][j+1] < f[i][j])
					{
						f[i][j] = f[rows[k]][j+1];
						nex[i][j] = rows[k];
					}
				}
				f[i][j] += a[i][j];
				if(j == 0 && f[i][0] < ans)
				{
					ans = f[i][0];
					fir = i;
				}
			}
		printf("%d", fir+1);
		for(int i = nex[fir][0], j = 1; j < n; i = nex[i][j], j++)
			printf(" %d", i+1);
		printf("\n%d\n", ans);
	}
	return 0;
}
