#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 2507;

int n, m, ans;
int a[Maxn][Maxn], sl[Maxn][Maxn], sd[Maxn][Maxn], su[Maxn][Maxn];
int f[Maxn][Maxn][2];

inline void read(int &);
inline int min3(int a, int b, int c) { return min(min(a, b), c); }
inline int max3(int a, int b, int c) { return max(max(a, b), c); }

int main()
{
	read(n); read(m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			read(a[i][j]);
			if(a[i][j]) sl[i][j] = sd[i][j] = 0;
			else sl[i][j] = sl[i][j-1]+1, su[i][j] = su[i-1][j]+1;
		}

	for(int j = 1; j <= m; ++j)
		for(int i = n; i; --i)
			if(a[i][j]) sd[i][j] = 0;
			else sd[i][j] = sd[i+1][j]+1;

	for(int j = 1; j <= m; ++j)
		for(int i = 1; i <= n; ++i)
			if(a[i][j])
			{
				f[i][j][0] = min3(f[i-1][j-1][0], sl[i][j-1], su[i-1][j])+1;
				f[i][j][1] = min3(f[i+1][j-1][1], sl[i][j-1], sd[i+1][j])+1;
				ans = max3(ans, f[i][j][0], f[i][j][1]);
			}
	printf("%d\n", ans);
	return 0;
}

inline void read(int &x) { char c; while((c=getchar()) < '0' || c > '9'); x = c-'0'; while((c=getchar()) >= '0' && c <= '9') x = (x<<3)+(x<<1) + c-'0'; }
