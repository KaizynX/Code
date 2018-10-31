#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+7;
const int MOD = 1e9+9;

int t, n;
int C[Maxn][Maxn], f[Maxn];

int solve(int rest, int last)
{
	if(!rest) return 1;
	int res = 0;
	for(int i = min(rest, last); i; --i)
	{
		res = (res + 1ll*f[i]*C[rest][i]%MOD*solve(rest-i, i)%MOD)%MOD;
	}
	return res;
}

inline void init()
{
	const int N = 1e1;

	C[0][0] = 1;
	for(int i = 1; i <= N; ++i)
	{
		C[i][0] = C[i][i] = 1;
		C[i][1] = C[i][i-1] = i;
		for(int j = 2; j <= i/2; ++j)
			C[i][j] = C[i][i-j] = (C[i-1][j]+C[i-1][j-1])%MOD;
	}

	f[0] = f[1] = 1;
	for(int i = 2; i <= N; ++i)
		f[i] = (1ll*i*solve(i-1, i-1))%MOD;
}

int main()
{
	init();
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		printf("%d\n", f[n]);
	}
	return 0;
}
