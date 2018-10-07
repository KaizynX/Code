#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn = 1007;

int n, ans;

struct Node
{
	int s, f;
	bool operator < (const Node &b) const
	{
		return (s == b.s) ? f < b.f : s < b.s;
	}
} a[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d%d", &a[i].s, &a[i].f);
	sort(a, a+n);
	for(int i = 0, last = -66666; i < n; ++i)
	{
		if(a[i].s > last)
		{
			ans++;
			last = a[i].f;
		}
		else
		{
			last = min(last, a[i].f);
		}
	}
	printf("%d\n", ans);
	return 0;
}
