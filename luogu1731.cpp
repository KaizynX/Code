#include <iostream>
#include <cstdio>

using namespace std;

int n, m, ans;

void dfs(int r, int h, int v, int d, int s)
{
	if(d == m)
	{
		++r; ++h;
		for( ; h*r*r+v <= n; ++r)
		{
			if((n-v) % (r*r)) continue;
			else if((n-v)/(r*r) < h) continue;
			else 
			{
				int hi = (n-v)/(r*r);
				if(!ans) ans = s+hi*2*r + r*r;
				else ans = min(ans, s+hi*2*r + r*r);
				// if(ans == 68) printf("%d %d %d\n", s, hi, r);
			}
		}
		return;
	}

	++h; ++r;
	for(; h*r*r+v < n; ++r)
		for(int hi = h ; hi*r*r < n; ++hi)
		{
			if(ans && s+2*hi*r > ans) break;
			dfs(r, hi, v+r*r*hi, d+1, s+2*hi*r);
		}
}

int main()
{
	scanf("%d%d", &n, &m);
	dfs(0, 0, 0, 1, 0);
	printf("%d\n", ans);
	return 0;
}
