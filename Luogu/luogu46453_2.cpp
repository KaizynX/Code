#include <bits/stdc++.h>

using namespace std;

const int Maxn = 807;
const int INF = 0x3f3f3f3f;

int n, m, w, t[3], ans = -1;
int dw[Maxn], dt[Maxn];
int a[Maxn][Maxn];

struct Node
{
	int dis, id;
	bool operator < (const Node &b) const { return dis < b.dis; }
} dd[Maxn];

template <typename T> inline void read(T &);

int main()
{
	read(n); read(m);
	memset(a, -1, sizeof a);
	for(int i = 1, u, v, c; i <= m; ++i)
	{
		read(u); read(v); read(c);
		a[u][v] = c;
	}
	read(w);
	for(int i = 0; i < 3; ++i) read(t[i]);

	for(int i = 1; i <= n; ++i)
	{
		dw[i] = a[w][i];
		if(i == w || i == t[0] || i == t[1] || i == t[2]) continue;
		for(int j = 1; j <= n; ++j)
		{
			if(j == w || j == t[0] || j == t[1] || j == t[2] || j == i) continue;
			if(a[w][j] == -1 || a[j][i] == -1) continue;
			dw[i] = max(dw[i], a[w][j]+a[j][i]);
		}
	}
	memset(dt, -1, sizeof dt);
	for(int k = 0 ; k < 3; ++k)
	{
		for(int i = 1; i <= n; ++i)
		{
			dt[i] = max(dt[i], a[t[k]][i]);
			if(i == t[k] || i == t[0] || i == t[1] || i == t[2]) continue;
			for(int j = 1; j <= n; ++j)
			{
				if(j == t[k] || j == t[0] || j == t[1] || j == t[2] || j == i) continue;
				if(a[t[k]][j] == -1 || a[j][i] == -1) continue;
				dt[i] = max(dt[i], a[t[k]][j]+a[j][i]);
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		dd[i].dis = dt[i];
		dd[i].id = i;
	}
	sort(dd+1, dd+n+1);

	for(int i = 1; i <= n; ++i)
	{
		int now = dd[i].id, flag = 0;
		if(now == w) continue;
		for(int j = 0; j < 3; ++j)
			if(now == t[j]) flag = 1;
		if(flag) continue;
		// first, THREE can see hardest
		if(ans != -1 && dt[now] > dt[ans]) break;
		// EARTH can see
		if(dw[now] == -1) continue;
		// EARTH can see easilest && id smallest
		if(ans == -1 || dw[now] > dw[ans] || (dw[now] == dw[ans] && now < ans))
			ans = now;
	}
	printf("%d\n", ans);
	return 0;
}

template <typename T> inline void read(T &x)
{
	char c;
	while(!isdigit((c=getchar())));
	x = c-'0';
	while(isdigit((c=getchar())))
		x = (x<<1)+(x<<3) + c-'0';
}
