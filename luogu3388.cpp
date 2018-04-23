#include <iostream>
#include <cstring>

using namespace std;

const int Maxn = 1e+6 + 7;

int n, m, ans, tot;
int u[Maxn], v[Maxn], fir[Maxn], nex[Maxn];
int depth, dfn[Maxn], low[Maxn];
bool flag[Maxn];

void add_edge(int x,int y)
{
	++tot;
	u[tot] = x;
	v[tot] = y;
	nex[tot] = fir[x];
	fir[x] = tot;
}

void tarjan(int cur, int father)
{
	int child = 0, nexv;
	++depth;
	dfn[cur] = depth;
	low[cur] = depth;
	for(int k = fir[cur]; k; k = nex[k])
	{
		nexv = v[k];
		if(!dfn[nexv])
		{
			++child;
			tarjan(nexv, father);
			low[cur] = min(low[cur], low[nexv]);
			// only root cur == father
			if(cur != father && low[nexv] >= dfn[cur])
				flag[cur] = true;
		}
		// if nexv has been visited, and you can reach it,update low
		low[cur] = min(low[cur], dfn[nexv]);
	}
	// the point must connect more than two point that it can be ***
	if(cur == father && child >= 2)
		flag[cur] = true;
}

int main()
{
	int x, y;
	cin >> n >> m;
	for (int i = 0; i < m; ++ i)
	{
		cin >> x >> y;
		add_edge(x,y);
		add_edge(y,x);
	}

	memset(flag, 0, sizeof flag);

	for(int i = 1; i <= n; ++ i)
	{
		if(!dfn[i])
		{
			tarjan(i,i);
		}
	}

	for(int i = 1; i <= n; ++ i)
	{
		if(flag[i])
			++ans;
	}

	cout << ans << endl;

	for(int i = 1; i <= n; ++ i)
	{
		if(flag[i])
			cout << i << ' ';
	}

	return 0;
}
