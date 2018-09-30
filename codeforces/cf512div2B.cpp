#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const double eps = 1e-5;

int d, n, m;

struct Line
{
	int a, b, k;
	// ax+by+k = 0
	
	inline void init(int x1, int y1, int x2, int y2)
	{
		int dx = x1-x2, dy = y1-y2;
		// y - y1 = (dx/dy)(x-x1)
		// dy*y-dy*y1 = dx*x-dx*x1
		// dx*x-dy*y-dx*x1+dy*y1 = 0
		a = dx; b = -dy;
		k = dy*y1-dx*x1;
		int gcd = __gcd(__gcd(a, b), k);
		a /= gcd; b /= gcd; k /= gcd;
#ifdef DEBUG
		printf("%+dx%+dy%+d=0\n", a, b, k);
#endif
	}

	inline double dis(int x, int y)
	{
		return abs((a*x+b*y+k))/sqrt(a*a+b*b);
	}
} l[4];

inline double point_dis(int x1, int y1, int x2, int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
	scanf("%d%d%d", &n, &d, &m);
	l[0].init(0, d, d, 0);
	l[1].init(n, n-d, n-d, n);
	l[2].init(0, d, n-d, n);
	l[3].init(d, 0, n, n-d);
	double len01 = point_dis(0, d, n-d, n),
		   len23 = point_dis(0, d, d, 0);
#ifdef DEBUG
	printf("%f %f\n", len01, len23);
#endif
	while(m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
#ifdef DEBUG
		printf("%f %f\n", l[0].dis(x, y)+l[1].dis(x, y), l[2].dis(x, y)+l[3].dis(x, y));
#endif
		if(abs(l[0].dis(x, y)+l[1].dis(x, y)-len01) < eps
		&& abs(l[2].dis(x, y)+l[3].dis(x, y)-len23) < eps)
			puts("YES");
		else puts("NO");
	}
	return 0;
}
