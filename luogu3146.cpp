#include <cstdio>
#include <iostream>
// #define DEBUG

using namespace std;

const int Maxn = 300;

int n, ans;
int f[Maxn][Maxn][2], is_one[Maxn][Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1, a; i <= n; ++i)
	{
		scanf("%d", &a);
		f[i][i][0] = f[i][i][1] = a;
		is_one[i][i] = 1;
	}
	for(int len = 2; len <= n; ++len)
	{
		for(int l = 1, r; l+len-1 <= n; ++l)
		{
			r = l+len-1;
			for(int k = l; k < r; ++k)
			{
				// [l, k] & [k+1, r]
				if(is_one[l][k] && is_one[k+1][r] && f[l][k][1] == f[k+1][r][0])
				{
					f[l][r][0] = f[l][r][1] = max(f[l][k][1]+1, max(f[l][r][0], f[l][r][1]));
					is_one[l][r] = 1;
					continue;
				}
				f[l][r][0] = max(f[l][r][0], f[l][k][0]);
				if(is_one[l][k] && f[l][k][1] == f[k+1][r][0])
					f[l][r][0] = max(f[l][r][0], f[l][k][1]+1);

				f[l][r][1] = max(f[l][r][1], f[k+1][r][1]);
				if(is_one[k+1][r] && f[l][k][1] == f[k+1][r][0])
					f[l][r][1] = max(f[l][r][1], f[k+1][r][0]+1);
#ifdef DEBUG
				printf("l:%d r:%d k:%d f_left:%d f_right:%d\n", l, r, k, f[l][r][0], f[l][r][1]);
#endif
			}
			ans = max(ans, max(f[l][r][0], f[l][r][1]));
		}
	}
	printf("%d\n", ans);
	return 0;
}
