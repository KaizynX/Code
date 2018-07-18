#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn = 1e3 + 7;

int n;

struct Node
{
	int a, b, num;
	bool operator < (const Node &nex) const
	{
		return min(a, b) < min(nex.a, nex.b);
	}
} c[Maxn], res[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) c[i].num = i;
	for(int i = 1; i <= n; ++i) scanf("%d", &c[i].a);
	for(int i = 1; i <= n; ++i) scanf("%d", &c[i].b);
	sort(c+1, c+n+1);
	for(int i = 1, l = 1, r = n; i <= n; ++i)
	{
		if(c[i].a < c[i].b) res[l++] = c[i];
		else res[r--] = c[i];
	}
	int ta = 0, tb = 0;
	for(int i = 1; i <= n; ++i)
	{
		ta += res[i].a;
		tb = max(tb, ta);
		tb += res[i].b;
	}
	printf("%d\n%d", tb, res[1].num);
	for(int i = 2; i <= n; ++i)
		printf(" %d", res[i].num);
	return 0;
}
