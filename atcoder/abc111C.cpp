#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n, a;
int f[2][Maxn], m[2][Maxn];

// 0 small 1 big

int main()
{
	scanf("%d%d", &n, &a);
	f[0][1] = f[1][1] = 1;
	m[0][1] = m[1][1] = 1;
	for(int i = 2, a; i <= n; ++i)
	{
		scanf("%d", &a);
		if(a > m[0][i-1])
		{
			f[1][i] = f[0][i-1]+1;
			m[1][i] = a;
		}
		else if(f[0][i] <= f[0][i-1])
		{
			f[0][i] = f[0][i-1];
			m[0][i] = 0;
		}

		if(a < m[1][i-1])
		{
			f[0][i] = f[1][i-1]+1;
			m[0][i] = a;
		}
		else if(f[1][i] <= f[1][i-1])
		{
			f[1][i] = f[1][i-1];
			m[1][i] = Maxn;
		}
	}
	printf("%d\n", n-max(f[0][n], f[1][n]));
	return 0;
}
