#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e3+7;

int n, cnt, vis[Maxn];
double ans, dis[Maxn];
typedef pair<double, int> _pair;
priority_queue<_pair, vector<_pair>, greater<_pair> > q;

struct Node
{
	int x, y;
} a[Maxn];

inline double calc(int i, int j)
{
	return sqrt((double)(a[i].x-a[j].x)*(a[i].x-a[j].x)+(double)(a[i].y-a[j].y)*(a[i].y-a[j].y));
}

inline void read(int &x)
{
	char c; int tag = 1;
	while(!isdigit(c=getchar())) if(c == '-') tag = -1;
	x = c-'0';
	while(isdigit(c=getchar())) x = (x<<1)+(x<<3) + c-'0';
	x *= tag;
}

inline void prim()
{
	vis[1] = 1;
	for(int i = 2; i <= n; ++i)
		q.push(make_pair(calc(1, i), i));
	_pair cur;
	int now;
	for(int cnt = 1; cnt < n;)
	{
		cur = q.top();
		q.pop();
		now = cur.second;
		if(vis[now]) continue;
		vis[now] = 1;
		ans += cur.first;
		cnt++;
		for(int i = 1; i <= n; ++i)
			if(!vis[i]) q.push(make_pair(calc(now, i), i));
	}
}

int main()
{
	read(n);
	for(int i = 1; i <= n; ++i)
		read(a[i].x), read(a[i].y);
	prim();
	printf("%.2f\n", ans);
	return 0;
}
