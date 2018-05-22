#pragma GCC optimize("inline")
#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 5e5 + 7;

int n, m;
int b[Maxn];

inline void add(int i,int x)
{
	for( ;i <= n; i += i & -i) b[i] += x;
}

inline int query(int x, int y)
{
	int res_x = 0, res_y = 0;
	for( ; y; y -= y & -y) res_y += b[y];
	for(--x; x; x -= x & -x) res_x += b[x];
	return res_y - res_x;
}

inline int getint()
{
	char c; bool tag = false;
	while((c=getchar()) < '0' || c > '9') if (c == '-') tag = true;
	int res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = (res<<1)+(res<<3) + c-'0';
	return tag ? -res : res;
}

int main()
{
	n = getint(); m = getint();
	for(int i = 1, tmp; i <= n; ++i)
	{
		tmp = getint();
		add(i,tmp);
	}
	for(int i = 1, x, y, op; i <= m; ++i)
	{
		op = getint(); x = getint(); y = getint();
		if(op == 1) add(x,y);
		else printf("%d\n",query(x,y));
	}
	return 0;
}
