#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int Maxm = 30;

int n, m, ans;
int r[Maxm], h[Maxm];
int minv[Maxm], mins[Maxm];

void dfs(int v, int dep, int s) // from bottom to top
{
	// finish
	if(dep == 0)
	{
		if(v == n)
		{
			if(!ans) ans = s;
			else ans = min(ans, s);
		}
		return;
	}

	// cut
	if(ans && s >= ans) return;
	if(ans && s + mins[dep] > ans) return;
	if(ans && s + 2*(n-v)/r[dep+1] > ans) return;
	if(v + minv[dep] > n) return;

	// search
	for(r[dep] = min((int)sqrt((n-v)/dep), r[dep+1]-1); r[dep] >= dep; --r[dep])
		for(h[dep] = min((n-v)/r[dep]/r[dep], h[dep+1]-1); h[dep] >= dep; --h[dep])
			dfs(v+r[dep]*r[dep]*h[dep], dep-1, s+2*r[dep]*h[dep]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i)
	{
		// r = i, h = i
		minv[i] = minv[i-1] + i*i*i;
		mins[i] = mins[i-1] + 2*i*i;
	}
	// bottom
	for(r[m] = (int)sqrt(n/m); r[m] >= m; --r[m])
		for(h[m] = n/r[m]/r[m]; h[m] >= m; --h[m])
			dfs(r[m]*r[m]*h[m], m-1, 2*r[m]*h[m] + r[m]*r[m]);
	printf("%d\n", ans);
	return 0;
}
