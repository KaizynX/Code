#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int Maxn = 200 + 7;
const int Maxq = 50000 + 7;
const int INF = 0x3f3f3f3f;

int n, m, num;
int t[Maxn];
int a[Maxn][Maxn];
int d[Maxn][Maxn]; // dis

inline bool cmp_t(int, int);
inline bool cmp_q(int, int);
inline int getint();
inline void floyd(int);

int main()
{
	int u, v, w;
	n = getint();
	m = getint();
	memset(d,0x3f,sizeof d);
	memset(a,-1,sizeof a);
	// read the time of every point
	for(int i = 0; i < n; ++i)
	{
		t[i] = getint();
		// init d[i][i]
		d[i][i] = 0;
	}
	// read the every edge
	for(int i = 0; i < m; ++i)
	{
		u = getint();
		v = getint();
		w = getint();
		a[u][v] = w;
		a[v][u] = w;
	}
	// read the query
	num = getint();
	int qx, qy, qt;
	u = 0;
	for(int i = 0; i < num; ++i)
	{
		qx = getint();
		qy = getint();
		qt = getint();
		// add the point we could reach in this query's time
		while(u < n && qt >= t[u])
		{
			// now u had been fixed
			// update the d[cur][i]
			for(v = 0; v < n; ++v)
			{
				if(t[v] > qt) continue;
				d[u][v] = min(d[u][v],a[u][v]);
			}
			// update d[i][j] that through u
			floyd(u);
			++u;
		}
		printf("%d\n",d[qx][qy] == INF ? -1 : d[qx][qy]);
	}
	return 0;
}

inline void floyd(int k)
{
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(d[i][j] > d[i][k] + d[k][j])
				d[i][j] = d[i][k] + d[k][j];
}

inline int getint()
{
	int res = 0;
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res;
}

