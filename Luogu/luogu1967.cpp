#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e4+7;
const int Maxm = 5e4+7;
const int Maxq = 3e4+7;
const int INF = 0x3f3f3f3f;

int n, m, q, tot;
int fa[Maxn], lg2[Maxn];
int fir[Maxn], nex[Maxn<<1], ver[Maxn<<1], w[Maxn<<1];
int f[Maxn][20], s[Maxn][20], d[Maxn];

struct Edge
{
	int x, y, z;
	bool operator < (const Edge &b) const { return z > b.z; }
} e[Maxm];

int getf(int);
void build_tree(int);
inline void read(int &);
inline void put(int);
inline void add_edge(int, int, int);
inline int query(int, int);

int main()
{
	read(n); read(m);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	for(int i = 0; i < m; ++i)
	{
		read(e[i].x);
		read(e[i].y);
		read(e[i].z);
	}
	// Kruscal
	sort(e, e+m);
	for(int i = 0, cnt = 0; i < m; ++i)
	{
		int fx = getf(e[i].x), fy = getf(e[i].y);
		if(fx == fy) continue;
		else
		{
			fa[fx] = fy;
			add_edge(e[i].x, e[i].y, e[i].z);
			add_edge(e[i].y, e[i].x, e[i].z);
			if(++cnt == n-1) break;
		}
	}
	// LCA
	for(int i = 2; i <= n; ++i) lg2[i] = lg2[i>>1]+1;
	for(int i = 1; i <= n; ++i)
	{
		if(getf(i) == i)
		{
			d[i] = 1;
			build_tree(i);
		}
	}
	read(q);
	for(int i = 0, x, y; i < q; ++i)
	{
		read(x); read(y);
		if(getf(x) != getf(y)) puts("-1");
		// else printf("%d\n", query(x, y));
		else put(query(x, y)), putchar('\n');
	}
	return 0;
}

void build_tree(int cur)
{
	for(int i = 1; i <= lg2[d[cur]]; ++i)
	{
		// s[cur][i] = s[cur][i-1]+s[f[cur][i-1]][i-1];
		s[cur][i] = min(s[cur][i-1], s[f[cur][i-1]][i-1]);
		f[cur][i] = f[f[cur][i-1]][i-1];
	}
	for(int i = fir[cur], to; i; i = nex[i])
	{
		to = ver[i];
		if(d[to]) continue; // visited
		f[to][0] = cur;
		s[to][0] = w[i];
		d[to] = d[cur]+1;
		build_tree(to);
	}
}

inline int query(int x, int y)
{
	int res = INF;
	// assume d[x] <= d[y]
	if(d[x] < d[y]) swap(x, y);
	while(d[x] > d[y])
	{
		// res += s[x][lg2[d[x]-d[y]]];
		res = min(res, s[x][lg2[d[x]-d[y]]]);
		x = f[x][lg2[d[x]-d[y]]];
	}
	if(x == y) return res;
	for(int i = lg2[d[x]]; i >= 0; --i)
		if(f[x][i] != f[y][i])
		{
			// res += s[x][i]+s[y][i];
			res = min(res, min(s[x][i], s[y][i]));
			x = f[x][i]; y = f[y][i];
		}
	// return res+s[x][0]+s[y][0];
	return min(res, min(s[x][0], s[y][0]));
}

inline void add_edge(int x, int y, int z)
{
	ver[++tot] = y; w[tot] = z; nex[tot] = fir[x]; fir[x] = tot;
}

int getf(int s)
{
	return fa[s] == s ? s : fa[s] = getf(fa[s]);
}

inline void read(int &x)
{
	char c;
	while((c=getchar()) < '0' || c > '9');
	x = c-'0';
	while((c=getchar()) >= '0' && c <= '9')
		x = (x<<1)+(x<<3) + c-'0';
}

inline void put(int x)
{
	if(x/10) put(x/10);
	putchar(x%10+'0');
}
