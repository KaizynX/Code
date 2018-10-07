#include <iostream>
#include <cstdio>

using namespace std;

const int Maxm = 10 + 2;
const int Maxn = 100 + 7;
const int INF = 0x7fffffff;

int n, m;
int a[Maxm][Maxn], f[Maxm][Maxn], nex[Maxm][Maxn];

int main()
{
	while(scanf("%d%d", &m, &n) == 2)
	{
		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j)
				scanf("%d", &a[i][j]);

		int mini, minv = INF;
		for(int j = n-1; j >= 0; --j)
			for(int i = 0; i < m; ++i)
			{
				if(j == n-1) { f[i][j] = a[i][j]; continue; } // right edge
				f[i][j] = INF;
				nex[i][j] = INF;
				for(int k = -1, row, val; k <= 1; ++k) // three direction
				{
					row = (i + k + m) % m;
					val = a[i][j] + f[row][j+1];
					if(val < f[i][j])
					{
						f[i][j] = val;
						nex[i][j] = row;
					}
					else if(val == f[i][j]) // ensure the path is in order
						nex[i][j] = min(row, nex[i][j]);
				}
				if(j == 0 && f[i][0] < minv) { minv = f[i][0]; mini = i; }
			}

		printf("%d", mini+1);
		for(int j = 1, i = nex[mini][0]; j < n; i = nex[i][j], j++)
			printf(" %d", i+1);
		printf("\n%d\n", minv);
	}
	return 0;
}
