#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int Maxn = 1e4 + 7;

int T, n, l, w, ans;

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
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &n, &l, &w);
		ans = 0;
		for(int i = 0, p, r; i < n; ++i)
		{
			scanf("%d%d", &p, &r);
			if(r < (double)w/2) // delete it
			{
				--i;
				--n;
				continue;
			}
			double d = sqrt(r*r - (double)w/2*w/2);
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
				ans = 0; break;
			}
			while(cur < n && a[cur].l <= last)
				tmp = max(tmp, a[cur++].r);
			++ans;
			last = tmp;
		}
		if(last < l) ans = 0;
		printf("%d\n", ans);
	}
	return 0;
}
