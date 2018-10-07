#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define DEBUG

using namespace std;

const int Maxn = 1e4 + 7;

int n, l, w, ans;

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
	while(scanf("%d%d%d", &n, &l, &w) == 3)
	{
		ans = 0;
		for(int i = 0, p, r; i < n; ++i)
		{
			scanf("%d%d", &p, &r);
			if(r < w/2) // delete it
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
		for(int i = 0; i < n; )
		{
			tmp = 0;
			if(a[i].l > last)
			{
				ans = -1; break;
			}
			while(a[i].l <= last) tmp = max(tmp, a[i++].r);
			last = tmp;
			++ans;
#ifdef DEBUG
			printf("%f\n", last);
#endif
		}
		if(last < l) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}
