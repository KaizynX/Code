#include <iostream>
#include <cstdio>
#include <algorithm>
#define DEBUG

using namespace std;

const int Maxn = 1007;

int n;
struct Node
{
	int a, b, num;
	bool operator < (const Node &nex) const 
	{
		return (a - b) < (nex.a - nex.b);
	}
} c[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &c[i].a);
		c[i].num = i;
	}
	for(int i = 1; i <= n; ++i)
		scanf("%d", &c[i].b);
	sort(c+1, c+n+1);

	int ta = 0, tb = 0;
	for(int i = 1; i <= n; ++i)
	{
		ta += c[i].a;
		tb = max(ta, tb);
		tb += c[i].b;
#ifdef DEBUG
		printf("%d %d\n", ta, tb);
#endif
	}
	printf("%d\n%d", tb, c[1].num);
	for(int i = 2; i <= n; ++i)
		printf(" %d", c[i].num);
	return 0;
}
