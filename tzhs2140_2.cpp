#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn = 1e6 + 7;

int n, ans;
int fa[Maxn];

int getf(int son)
{
	return fa[son] == son ? fa[son] : fa[son] = getf(fa[son]);
}

struct Node
{
	int t, v;
	bool operator < (const Node &b) const
	{
		return v > b.v;
	}
} a[Maxn];

inline void read(int &);

int main()
{
	read(n);
	for(int i = 0; i < Maxn; ++i) fa[i] = i;
	for(int i = 0; i < n; ++i)
	{
		read(a[i].t);
		read(a[i].v);
	}
	sort(a, a+n);
	for(int i = 0, fd; i < n; ++i)
	{
		fd = getf(fa[ a[i].t ]);
		if(fd)
		{
			ans += a[i].v;
			fa[fd] = getf(fd-1);
		}
	}
	printf("%d\n", ans);
	return 0;
}

inline void read(int &x)
{
	char c;
	while((c=getchar()) < '0' || c > '9');
	x = c - '0';
	while((c=getchar()) >= '0' && c <= '9') x = (x<<1)+(x<<3) + c-'0';
}

