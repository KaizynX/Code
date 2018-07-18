#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int Maxn = 60;

int n, cnt, ans;
int x[Maxn], y[Maxn];
int fa[Maxn];

struct Edge
{
	int u, v, d;

	Edge(){}
	Edge(int u, int v, int d) : u(u), v(v), d(d) {}

	bool operator < (const Edge &b) const
	{
		return d < b.d;
	}
} e[Maxn*Maxn];

inline int dis(int i, int j)
{
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}

int getf(int s)
{
	return fa[s] == s ? s : fa[s] = getf(fa[s]);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d", x+i, y+i);
		fa[i] = i;
	}
	for(int i = 1; i < n; ++i)
		for(int j = i+1; j <= n; ++j)
			e[++cnt] = Edge(i, j, (dis(i, j)-1)/2+1);
	sort(e+1, e+cnt+1);
	for(int i = 1, co = 0, fu, fv; i <= cnt; ++i)
	{
		fu = getf(e[i].u);
		fv = getf(e[i].v);
		if(fu != fv)
		{
			fa[fu] = fv;
			ans = max(ans, e[i].d);
			if(++co == n-1) break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
