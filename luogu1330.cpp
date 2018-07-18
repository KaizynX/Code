#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

#define DEBUG

using namespace std;

const int Maxn = 1e+4 + 7;
const int Maxm = 1e+5 + 7;

int n, m, tot, ans;
int u[Maxm*2], v[Maxm*2], fir[Maxm*2], nex[Maxm*2];
int col[Maxn]; // 0 -> didn't be vised  1,2 -> different colors

inline int abs(int a) { return a < 0 ? -a : a; }

inline void add_edge(int now_u,int now_v)
{
	++tot;
	u[tot] = now_u;
	v[tot] = now_v;
	nex[tot] = fir[now_u];
	fir[now_u] = tot;
}

void bfs(int start)
{
	// paint the color
	// every edge connect two point
	// so we choose the color which has less points

	int cur, cnt = 0, num = 0;
	queue<int> q, mem_q;
	// cnt = 0;

	q.push(start);
	mem_q.push(start);
	col[start] = 1;

	while(!q.empty())
	{
		cur = q.front();
		q.pop();

		for(int k = fir[cur]; k; k = nex[k])
		{
			if(col[ v[k] ]) continue;
			
			q.push(v[k]);
			mem_q.push(v[k]);
			col[ v[k] ] = (col[cur] == 1 ? 2 : 1); // paint the different color
		}
	}
	// search the point we visit this time
	while(!mem_q.empty())
	{
		cur = mem_q.front();
		if(col[cur] == 1) cnt++;
		++num;
		mem_q.pop();
	}

	ans += min(cnt, abs(num - cnt));
#ifdef DEBUG
	printf("%d %d %d %d\n",start,num,cnt,ans);
#endif
}

int main()
{
	int tmp_u,tmp_v;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < m; ++i)
	{
		scanf("%d%d",&tmp_u, &tmp_v);
		add_edge(tmp_u,tmp_v);
		add_edge(tmp_v,tmp_u);
	}
	
	// if the point exit in V less than n
	// if there is not only one V

	memset(col,0,sizeof col);
	for(int i = 1; i <= n; ++ i)
	{
		if(!col[i]) bfs(i);
	}
	// the two points between one edge must have different color
	for(int i = 1; i <= tot; ++i)
	{
		if(col[ u[i] ] == col[ v[i] ])
		{
			printf("Impossible\n");
			return 0;
		}
	}

	printf("%d\n",ans);
	return 0;
}
