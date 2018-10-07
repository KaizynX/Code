#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int Maxn = 60;

int n;
int x[Maxn], y[Maxn], e[Maxn][Maxn][Maxn][Maxn];
int q[100], head, tail;
bool vis[Maxn];

inline int dis(int i, int j)
{
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

bool check(int mid)
{
	// bfs
	memset(vis, 0, sizeof vis);
	int cnt = 1, cur;
	head = tail = 0;
	q[++tail] = 1;
	vis[1] = true;
	while(head < tail)
	{
		cur = q[++head];
		for(int i = 2, tmp; i <= n; ++i)
		{
			if(vis[i]) continue;
			if((tmp=e[x[cur]][y[cur]][x[i]][y[i]]) == -1 || tmp > mid) continue;
			vis[i] = true;
			++cnt;
			q[++tail] = i;
		}
	}
	return cnt >= n;
}

int main()
{
	int l = 0x7fffffff, r = 0;
	memset(e, -1, sizeof e);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", x+i, y+i);
	for(int i = 1; i < n; ++i)
		for(int j = i+1, tmp; j <= n; ++j)
		{
			tmp = e[x[i]][y[i]][x[j]][y[j]] = e[x[j]][y[j]][x[i]][y[i]] = dis(i, j) / 2;
			l = min(l, tmp);
			r = max(r, tmp);
		}
	while(l < r)
	{
		int mid = (l+r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}
