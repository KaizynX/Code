#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e3+7;
const double INF = 1e18;

int n, cnt, vis[Maxn];
double ans, dis[Maxn];

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
	fill(dis, dis+n+1, INF);
	dis[1] = 0;
	for(int t = 1; t <= n; ++t)
	{
		int mini = 0;
		for(int i = 1; i <= n; ++i)
			if(!vis[i] && dis[i] < dis[mini])
				mini = i;

		vis[mini] = 1;
        ans += dis[mini];

		for(int i = 1; i <= n; ++i)
			if(!vis[i]) dis[i] = min(dis[i], calc(mini, i));
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
