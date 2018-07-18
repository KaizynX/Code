#include <iostream>
#include <cstdio>
#include <algorithm>

#define DEBUG

using namespace std;

const int Maxm = 5000 + 7;
const int Maxn = 10000 + 7;

int n, r, ans, minx, maxx, miny, maxy;
int s[Maxm][Maxm];
struct Point
{
	int x, y, v;
	bool operator < (const Point &b) const
	{
		return x == b.x ? y < b.y : x < b.x;
	}
} a[Maxn];

inline int getint();

int main()
{
	n = getint(); r = getint();
	minx = Maxm; miny = Maxm; // maxx = 0; maxy = 0;
	for(int i = 0,x,y,v; i < n; ++i)
	{
		x = getint(); y = getint(); v = getint();
		// x,y may == 0;
		++x; ++y;
		if(x < minx) minx = x; 
		if(x > maxx) maxx = x;
		if(y < miny) miny = y; 
		if(y > maxy) maxy = y;
		a[i].x = x; a[i].y = y; a[i].v = v;
	}
	sort(a,a+n);
	for(int i = minx,cur = 0; i <= maxx; ++i)
	{
		for(int j = minx; j <= maxy; ++j)
		{
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1];
			// we don't need to consider the case than cur == n
			if(i == a[cur].x && j == a[cur].y) s[i][j] += a[cur++].v;
#ifdef DEBUG
			printf("%2d ",s[i][j]);
#endif
		}
#ifdef DEBUG
		putchar('\n');
#endif
	}
	for(int i = minx+r-1; i <= maxx; ++i)
		for(int j = miny+r-1; j <= maxy; ++j)
		{
			ans = max(ans,s[i][j] - s[i-r][j] - s[i][j-r] + s[i-r][j-r]);
		}

	printf("%d\n",ans);
	return 0;
}

inline int getint()
{
	char c;
	while((c=getchar()) < '0' || c > '9');
	int res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = (res<<1)+(res<<3) + c-'0';
	return res;
}

