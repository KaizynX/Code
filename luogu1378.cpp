#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int Maxn = 10;
const double PI = acos(-1);

struct Node
{
	int x, y;
	double r;
} a[Maxn];

int n, bx, by, ex, ey;
int order[Maxn];
double ri[Maxn];

inline double dis(int i, int j) // return the distance between two points
{
	return sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x) + (a[i].y-a[j].y)*(a[i].y-a[j].y));
}

inline double cal() // cal the place the square can cover in this order
{
	double res = 0.0;
	for(int i = 1, cur; i <= n; ++i)
	{
		cur = order[i];
		ri[cur] = a[cur].r;
		for(int j = 1; j < i; ++j)
			ri[cur] = min(ri[cur], dis(cur, order[j]) - ri[order[j]]);
		// Warning !!!
		if(ri[cur] < 0) ri[cur] = 0.0;
		res += PI * ri[cur] * ri[cur];
	}
	return res;
}

inline int out(double num) // ËÄÉáÎåÈë
{
	double floor_v = floor(num);
	return static_cast<int>(num - floor_v >= 0.5 ? floor_v+1 : floor_v);
}

inline int min4(int a, int b, int c, int d)
{
	int arr[4] = {a, b, c, d};
	sort(arr, arr+4);
	return arr[0];
}

int main()
{
	scanf("%d%d%d%d%d", &n, &bx, &by, &ex, &ey);
	for(int i = 1; i <= n; ++i) 
	{
		order[i] = i;
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].r = min4(abs(a[i].x-bx), abs(a[i].x-ex), abs(a[i].y-by), abs(a[i].y-ey));
	}
	double ans = 0.0;
	do ans = max(ans, cal());
	while(next_permutation(order+1, order+n+1));
	printf("%d\n", out(-ans + abs((bx-ex)*(by-ey)) ) );
	return 0;
}
