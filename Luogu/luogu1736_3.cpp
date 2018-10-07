#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 2507;

int n, m, ans;
int a[Maxn][Maxn], s[Maxn][Maxn];
int f[Maxn][Maxn][2];

// [0] 1 0 0  [1] 0 0 1
//     0 1 0      0 1 0
//     0 0 1      1 0 0

// (x, y) as right bottom, l as edge length
inline int calc(int x, int y, int l)
{
	return s[x][y]-s[x-l][y]-s[x][y-l]+s[x-l][y-l];
}

inline void read(int &x)
{
	char c;
	while((c=getchar()) < '0' || c > '9');
	x = c-'0';
	while((c=getchar()) >= '0' && c <= '9')
		x = (x<<3)+(x<<1) + c-'0';
}

int main()
{
	// scanf("%d%d", &n, &m);
	read(n); read(m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			// scanf("%d", &a[i][j]);
			read(a[i][j]);
			s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
		}

	for(int j = 1, l, r, mid; j <= m; ++j)
	{
		for(int i = 1; i <= n; ++i)
		{
			if(a[i][j])
			{
				l = 1; r = f[i-1][j-1][0]+1;
				while(l < r)
				{
					mid = (l+r+1)>>1;
					if(calc(i, j, mid) == mid) l = mid;
					else r = mid-1;
				}
				f[i][j][0] = l;

				l = 1; r = f[i+1][j-1][1]+1;
				while(l < r)
				{
					mid = (l+r+1)>>1;
					if(calc(i+mid-1, j, mid) == mid) l = mid;
					else r = mid-1;
				}
				f[i][j][1] = l;

				ans = max(ans, max(f[i][j][0], f[i][j][1]));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
