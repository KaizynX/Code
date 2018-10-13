#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e3+7;

int n, tot;
int fa[Maxn];
double ans;

struct Node
{
	int x, y;
} a[Maxn];

struct Edge
{
	int i, j;
	double d;
	bool operator < (const Edge &b) const { return d < b.d; }
} e[Maxn*Maxn>>1];

inline double calc(int i, int j)
{
	return sqrt((double)(a[i].x-a[j].x)*(a[i].x-a[j].x)+(double)(a[i].y-a[j].y)*(a[i].y-a[j].y));
}

int getf(int s)
{
	return fa[s] == s ? s : fa[s] = getf(fa[s]);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		for(int j = 1; j < i; ++j)
		{
			e[++tot].d = calc(i, j);
			e[tot].i = i; e[tot].j = j;
		}
	}

	sort(e+1, e+tot+1);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	for(int i = 1, cnt = 0; i <= tot && cnt < n-1; ++i)
	{
		int fi = getf(e[i].i), fj = getf(e[i].j);
		if(fi == fj) continue;
		fa[fi] = fj;
		ans += e[i].d;
		cnt++;
	}
	printf("%.2f\n", ans);
	return 0;
}
