#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int Maxn = 1000 + 7;
const int INF = 0x7f7f7f7f;

int n, d;

inline int getint();

struct P
{
	int x, y;
	bool operator < (const P &b) const
	{
		return x == b.x ? y > b.y : x < b.x;
	}
} a[Maxn];

int main()
{
	for(register int t = 1,flag = 0,ans = 0;; ++t, flag=0, ans = 0)
	{
		n = getint(); d = getint();
		if(n == 0 && d == 0) break;

		for(register int i = 0; i < n; ++i) 
		{
			a[i].x = getint(); a[i].y = getint();
			if(a[i].y > d) flag = 1;
		}
		if(flag) // no solution
		{
			printf("Case %d: -1\n",t);
			continue;
		}

		sort(a,a+n);
		for(register int i = 0, cur, pre = -INF; i < n; ++i)
		{
			cur = sqrt(d*d - a[i].y*a[i].y);
			if(a[i].x+cur < pre) pre = a[i].x+cur; // then a[i].x - cur must < pre
			else if(a[i].x-cur > pre) { pre = a[i].x+cur; ++ans; }
		}
		printf("Case %d: %d\n",t,ans);
	}
	return 0;
}

inline int getint()
{
	char c; bool tag = false;
	while((c=getchar()) < '0' || c > '9') if(c == '-') tag = true;
	int res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = res * 10 + c - '0';
	return tag == true ? -res : res;
}
