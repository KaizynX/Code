#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

#define DEBUG

using namespace std;

const int Maxn = 100 + 7;

int n;

struct E
{
	int u,v,d;
	bool operator < (const E &b) const
	{
		return d > b.d;
	}
}tmp;

priority_queue<E> q;

int fa[Maxn];

int findf(int s)
{
	if(fa[s] != s)
		fa[s] = findf(fa[s]);
	return fa[s];
}

bool connect(int x,int y)
{
	int fx = findf(x), fy = findf(y);
	if(fx != fy)
	{
		fa[x] = fy;
		return true;
	}
	else return false;
}

void init()
{
	for(int i = 1; i <= n; ++i)
	{
		fa[i] = i;
	}
}

int main()
{
	int dis, cnt = 0, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			cin >> dis;
			if(i < j)
			{
				tmp.u = i;
				tmp.v = j;
				tmp.d = dis;
				q.push(tmp);
			}
		}
	}

	init();
	// we only need n - 1 edge to connect all
	while(cnt < n - 1 && !q.empty())
	{
		tmp = q.top();
		q.pop();
#ifdef DEBUG
		printf("%d %d %d\n",tmp.u,tmp.v,tmp.d);
#endif
		if(connect(tmp.u, tmp.v))
		{
#ifdef DEBUG
			printf("%d %d\n",cnt,ans);
#endif
			ans += tmp.d;
			++cnt;
		}
	}
	
	cout << ans << endl;
	return 0;
}
