#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int Maxn = 2e5 + 7；

struct Node
{
	int x, y;
} a[Maxn];

inline int cal(int i, int j)
{
	return min( abs(a[i].x-a[j].x , a[i].y-a[j].y) );
}

int n;
int d[Maxn];

int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; ++ i)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}

	for(int i = 1; i < n; ++i)
	{
		;
	}

	return 0;
}
