#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 5e5 + 7;

int n, m;
int a[Maxn], b[Maxn];

inline int getint()
{
	char c; bool tag = false;
	while((c=getchar()) < '0' || c > '9') if (c == '-') tag = true;
	int res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = (res<<1)+(res<<3) + c-'0';
	return tag ? -res : res;
}

inline void add(int i, int k)
{
	for( ; i <= n; i += i & -i) b[i] += k;
}

inline int query(int x)
{
	int res = 0;
	for( ; x; x -= x & -x) res += b[x];
	return res;
}

int main()
{
	n = getint(); m = getint();
	for(int i = 1; i <= n; ++i) a[i] = getint();
	for(int i = 0, op, x, y, k; i < m; ++i)
	{
		op = getint(); x = getint();
		if(op == 1)
		{
			y = getint(); k = getint();
			add(x,k); add(y+1,-k);
		}
		else printf("%d\n",a[x] + query(x));
	}
	return 0;
}
