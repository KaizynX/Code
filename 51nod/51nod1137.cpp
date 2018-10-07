#include <bits/stdc++.h>

using namespace std;

const int Maxn = 107;

int n;

struct Match
{
	int m[Maxn][Maxn];

	Match(){ memset(m, 0, sizeof m); }

	inline void init() { for(int i = 0; i < Maxn; ++i) m[i][i] = 1; }

	Match operator * (const Match &b) const
	{
		Match res;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
			{
				int &cur = res.m[i][j];
				for(int k = 1; k <= n; ++k)
					cur = cur+m[i][k]*b.m[k][j];
			}
		return res;
	}
} a[2], ans;

int main()
{
	scanf("%d", &n);
	for(int k = 0; k < 2; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				scanf("%d", &a[k].m[i][j]);

	ans = a[0]*a[1];
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			printf("%d ", ans.m[i][j]);
		putchar('\n');
	}
	return 0;
}
