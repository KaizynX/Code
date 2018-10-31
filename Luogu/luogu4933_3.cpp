#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+7;
const int Maxv = 2e4+7;
const int MOD = 998244353;

int n, ans;
int a[Maxn], b[Maxn][Maxv<<1];
int *f[Maxn];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", a+i);
	for(int i = 1; i <= n; ++i) f[i] = b[i]+Maxv;
	for(int i = 1; i <= n; ++i)
	{
		ans++;
		for(int j = 1; j < i; ++j)
		{
			int d = a[i]-a[j];
			f[i][d] = (f[i][d]+f[j][d]+1)%MOD;
			ans = (ans+f[j][d]+1)%MOD;
		}
	}
	printf("%d\n", ans);
    return 0;
}
