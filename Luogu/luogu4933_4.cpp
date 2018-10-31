#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+7;
const int Maxv = 2e4+7;
const int MOD = 998244353;

int n, ans;
int a[Maxn], b[Maxn][Maxv<<1];
int *f[Maxn];

inline void read(int &x)
{
	char c; int tag = 1;
	while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
	x = c-'0';
	while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
	x *= tag;
}

int main()
{
	read(n); ans = n;
    for(int i = 1; i <= n; ++i) read(a[i]), f[i] = b[i]+Maxv;
	for(int i = 1; i <= n; ++i)
		for(int j = 1, d; j < i; ++j)
		{
			d = a[i]-a[j];
			f[i][d] = (f[i][d]+f[j][d]+1)%MOD;
			ans = (ans+f[j][d]+1)%MOD;
		}
	printf("%d\n", ans);
    return 0;
}
