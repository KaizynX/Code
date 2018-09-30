#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 2507;

int n, m, ans;
int a[Maxn][Maxn], st[Maxn][Maxn], sv[Maxn][Maxn], f[Maxn][Maxn];

inline void read(int &);
inline int min3(int a, int b, int c) { return min(min(a, b), c); }

int main()
{
	read(n); read(m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			read(a[i][j]);
			if(a[i][j]) st[i][j] = sv[i][j] = 0;
			else st[i][j] = st[i][j-1]+1, sv[i][j] = sv[i-1][j]+1;
		}

	for(int j = 1; j <= m; ++j)
		for(int i = 1; i <= n; ++i)
			if(a[i][j])
				ans = max(ans, f[i][j] = min3(f[i-1][j-1], st[i][j-1], sv[i-1][j])+1);

	for(int j = 1; j <= m; ++j)
		for(int i = n; i; --i)
			if(a[i][j]) sv[i][j] = 0;
			else sv[i][j] = sv[i+1][j]+1;

	for(int j = 1; j <= m; ++j)
		for(int i = 1; i <= n; ++i)
			if(a[i][j])
				ans = max(ans, f[i][j] = min3(f[i+1][j-1], st[i][j-1], sv[i+1][j])+1);

	printf("%d\n", ans);
	return 0;
}

inline void read(int &x) { char c; while((c=getchar()) < '0' || c > '9'); x = c-'0'; while((c=getchar()) >= '0' && c <= '9') x = (x<<3)+(x<<1) + c-'0'; }
