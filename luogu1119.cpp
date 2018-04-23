#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

#define DEBUG

using namespace std;

const int Maxn = 200 + 7;
const int Maxq = 50000 + 7;
const int INF = 0x3f3f3f3f;

int n, m, num;
int t[Maxn];
int a[Maxn][Maxn]; // edge
int d[Maxn][Maxn]; // dis
int ans[Maxn]; // answer for query
bool in_q[Maxn];

struct Q
{
	int x, y, t;
} q[Maxq];

inline bool cmp_t(int, int);
inline bool cmp_q(int, int);
inline int getint();
inline void floyd(int);
inline void bfs(int,int);

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
	for(int i = 0; i < num; ++i)
	{
		q[i].x = getint();
		q[i].y = getint();
		q[i].t = getint();
	}

	// sort it depend on time from small to big 
	int cur = 0;
	for(int i = 0; i < num; ++i)
	{
		// add the point we could reach in this query's time
		while(cur < n && q[i].t >= t[cur])
		{
			// now u had been fixed
			// update the d[cur][i]
			bfs(cur,q[i].t);
			// update d[i][j] that through u
			floyd(cur);
			++cur;
		}
		printf("%d\n",d[q[i].x][q[i].y] == INF ? -1 : d[q[i].x][q[i].y]);
	}
	return 0;
}

inline void bfs(int root,int now_t)
{
	int u;
	queue<int> q;
	memset(in_q,0,sizeof in_q);

	q.push(root);
	in_q[root] = true;
	while(!q.empty())
	{
		u = q.front();
		q.pop();

		for(int v = 0; v < n; ++v)
		{
			// the point is still fixing || there's no edge between them
			if(t[v] > now_t || a[u][v] == -1) continue;
			// add the edge
			// actually d[u][v] == d[v][u] == INF
			if(d[root][u] + a[u][v] < d[root][v])
			{
				d[root][v] = d[v][root] = d[root][u] + a[u][v];
				if(!in_q[v])
				{
					in_q[v] = true;
					q.push(v);
				}
			}
		}
		in_q[u] = false;
	}
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
