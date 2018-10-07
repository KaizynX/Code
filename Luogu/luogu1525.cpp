#include <iostream>
#include <algorithm>
#include <cstdio>

#define DEBUG

using namespace std;

const int Maxn = 20000 + 7;
const int Maxm = 1e+5 + 7;

int n, m, ans;
int fa[Maxn],en[Maxn]; // father & enemy

struct Edge
{
	int u, v, w;
	bool operator < (const Edge &b) const
	{
		return w > b.w;
	}
} e[Maxm];

inline int getint();
int getf(int s) { return fa[s] == s ? s : fa[s] = getf(fa[s]); }
inline void connect(int x, int y) // turn fa[x] to fa[en[y]]
{
	// now en[x] == 0
	fa[x] = getf( en[y] );
	en[x] = getf(y);
}

int main()
{
	n = getint();
	m = getint();
	for(int i = 1; i <= n; ++ i) fa[i] = i;
	for(int i = 0; i < m; ++ i)
	{
		e[i].u = getint();
		e[i].v = getint();
		e[i].w = getint();
	}
	sort(e,e + m);
	int u, v;
	for(int i = 0; i < m; ++ i)
	{
		u = e[i].u;
		v = e[i].v;
#ifdef DEBUG
		printf("%d %d  %d %d\n",u,en[u],v,en[v]);
#endif
		if(!en[u] && !en[v]) // haven't been visited yet
		{
			// send they to different prison
			en[u] = v;
			en[v] = u;
		}
		else if(en[u] && !en[v])
		{
			// send v to en[u]
			connect(v,u);
		}
		else if(!en[u] && en[v])
		{
			connect(u,v);
		}
		// next is en[u] && en[v]
		else if( getf(en[u]) != getf(en[v]) )
		{
			// connect this two pair
			fa[getf(u)] = getf(en[v]);
			fa[getf(v)] = getf(en[u]);
		}
		else // can't avoid this conflict
		{
			ans = e[i].w;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}

inline int getint()
{
	int res = 0;
	char c = getchar();
	while( c < '0' || c > '9') c = getchar();
	while( c >= '0'  && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res;
}
