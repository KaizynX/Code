#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e3+7;
const int Maxm = 5e6+7;
const long long INF = 1e15;

int n, tot, fa[Maxn];
double ans;

struct Node
{
	int x, y;
	bool operator < (const Node &b) const { return x < b.x; }
} a[Maxn];

struct Edge
{
	int i, j;
	long long d;
	bool operator < (const Edge &b) const { return d < b.d; }
} e[Maxm];

int getf(int s)
{
	return fa[s] == s ? s : fa[s] = getf(fa[s]);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i].x, &a[i].y);
	sort(a+1, a+n);
	for(int i = 1; i < n; ++i)
	{
		long long mind = INF;
		for(int j = i+1; j <= n; ++j)
		{
			if(a[j].x - a[i].x >= mind) break;
			e[++tot].d = (a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
			e[tot].i = i; e[tot].j = j;
			mind = min(mind, e[tot].d);
		}
	}

	sort(e+1, e+tot+1);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	for(int i = 1, cnt = 0; i <= tot && cnt < n-1; ++i)
	{
		int fi = getf(e[i].i), fj = getf(e[i].j);
		if(fi == fj) continue;
		fa[fi] = fj;
		ans += sqrt(e[i].d);
		cnt++;
	}
	printf("%.2f\n", ans);
	return 0;
}
