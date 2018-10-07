#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int Maxn = 1e4 + 7;

int n, ans;
double l, w;

struct Node
{
	double l, r;
	bool operator < (const Node &b) const
	{
		return l < b.l;
	}
} a[Maxn];

int main()
{
	while(scanf("%d%lf%lf", &n, &l, &w) == 3)
	{
		double p, r;
		ans = 0;
		for(int i = 0; i < n; ++i)
		{
			scanf("%lf%lf", &p, &r);
			if(r < w/2) // delete it
			{
				--i;
				--n;
				continue;
			}
			double d = sqrt(r*r - w/2*w/2);
			a[i].l = -d + p;
			a[i].r = d + p;
		}
		sort(a, a+n);
		double last = 0, tmp;
		int cur = 0;
		while(last < l && cur < n)
		{
			tmp = 0;
			if(a[cur].l > last)
			{
				ans = -1; break;
			}
			while(cur < n && a[cur].l <= last)
				tmp = max(tmp, a[cur++].r);
			++ans;
			last = tmp;
		}
		if(last < l) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}
