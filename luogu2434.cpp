#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 5e4+7;

int n;
struct Node
{
	int l, r;
	bool operator < (const Node &b) const
	{
		return l < b.l;
	}
} a[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d%d", &a[i].l, &a[i].r);
	sort(a, a+n);
	int lastl = a[0].l, lastr = a[0].r;
	for(int i = 1; i <= n; ++i)
	{
		if(a[i].l <= lastr) lastr = max(lastr, a[i].r);
		else
		{
			printf("%d %d\n", lastl, lastr);
			lastl = a[i].l;
			lastr = a[i].r;
		}
	}
	printf("%d %d\n", lastl, lastr);
	return 0;
}
