#include <bits/stdc++.h>

using namespace std;

const int Maxn = 107;
const int MOD = 1e9+7;

int n, m;

struct Match
{
	long long m[Maxn][Maxn];

	Match(){ memset(m, 0, sizeof m); }

	inline void init() { for(int i = 0; i < Maxn; ++i) m[i][i] = 1; }

	Match operator * (const Match &b) const
	{
		Match res;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
			{
				long long &cur = res.m[i][j];
				for(int k = 1; k <= n; ++k)
					cur = (cur+m[i][k]*b.m[k][j])%MOD;
			}
		return res;
	}

} a, ans;

inline Match qpow(Match a, int p)
{
	Match res;
	res.init();
	while(p)
	{
		if(p&1) res = res*a;
		p >>= 1;
		a = a*a;
	}
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%lld", &a.m[i][j]);

	ans = qpow(a, m);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			printf("%lld ", ans.m[i][j]);
		putchar('\n');
	}
	return 0;
}
