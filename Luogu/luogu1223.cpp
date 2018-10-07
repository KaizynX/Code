#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e3+7;

int n, cur;
double sum;
struct Node
{
	int t, num;
	bool operator < (const Node &b) const
	{
		return t < b.t;
	}
} a[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i].t);
		a[i].num = i;
	}
	sort(a+1, a+n+1);
	for(int i = 1; i < n; ++i)
	{
		printf("%d ", a[i].num);
		sum += cur;
		cur += a[i].t;
	}
	sum += cur;
	printf("%d\n%.2f\n", a[n].num, sum/n);
	return 0;
}
