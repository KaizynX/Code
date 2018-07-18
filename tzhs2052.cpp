#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

const int Maxn = 100 + 5;
const int INF = INT_MAX;

int n,ans = INF;
bool vis[Maxn];

struct tree
{
	int v = 0, u = 0, l = 0, r = 0;
} tr[Maxn];

int bfs(int i, int depth)
{
	if(vis[i]) return 0;
	vis[i] = true;
	int res = 0;
	res += tr[i].v * depth;
	if(tr[i].u) res += bfs(tr[i].u, depth + 1);
	if(tr[i].l) res += bfs(tr[i].l, depth + 1);
	if(tr[i].r) res += bfs(tr[i].r, depth + 1);
	return res;
}

int main()
{
	int v,l,r;
	scanf("%d",&n);
	for(int i = 1; i <= n; ++ i)
	{
		scanf("%d%d%d",&v,&l,&r);
		tr[i].v = v;
		tr[i].l = l;
		tr[i].r = r;
		if(l) tr[l].u = i;
		if(r) tr[r].u = i;
	}
	for(int i = 1; i <= n; ++ i)
	{
		memset(vis, 0, sizeof vis);
		ans = min(ans, bfs(i,0) );
	}
	printf("%d\n",ans);
	return 0;
}
