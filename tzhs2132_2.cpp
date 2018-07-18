#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn = 1007;

int n, ans = 1;

struct Node
{
	int s, f;
	bool operator < (const Node &b) const
	{
		return (f == b.f) ? s < b.s : f < b.f;
	}
} a[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d%d", &a[i].s, &a[i].f);
	sort(a, a+n);
	for(int i = 1, last = a[0].f; i < n; ++i)
	{
		if(a[i].s >= last)
		{
			++ans;
			last = a[i].f;
		}
	}
	printf("%d\n", ans);
	return 0;
}
