#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e5+7;

int n, s, ans;
int log2[Maxn], fa[Maxn][20], v[Maxn][20];

int main()
{
	scanf("%d%d", &n, &s);
	for(int i = 2; i <= n; ++i)
		log2[i] = log2[i>>1]+1;
	for(int i = 1; i <= n; ++i)
		scanf("%d", &v[i][0]);
	for(int i = 1, x, y; i < n; ++i)
	{
		scanf("%d%d", &x, &y);
		fa[y][0] = x;
	}
	for(int i = 1; i <= log2[n]; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			fa[j][i] = fa[fa[j][i-1]][i-1];
			v[j][i] = v[j][i-1]+v[fa[j][i-1]][i-1];
		}
	}
	for(int i = 1, cnt, cur; i <= n; ++i)
	{
		cnt = 0;
		cur = i;
		for(int j = log2[n]; j >= 0; --j)
		{
			if(cnt+v[cur][j] <= s)
			{
				cnt += v[cur][j];
				cur = fa[cur][j];
			}
			if(cnt == s)
			{
				++ans;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
