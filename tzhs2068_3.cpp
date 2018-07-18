#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn = 2e5 + 7;
const int INF = 2e9;

int n, ans;
struct Node
{
	int l, r;
	bool operator < (const Node &b) const { return r < b.r; }
} a[Maxn];

inline void read(int &res)
{
	char c; int tag = 1;
	while((c=getchar()) < '0' || c > '9') if(c == '-') tag = -1;
	res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = (res<<1)+(res<<3) + c-'0';
	res *= tag;
}

int main()
{
	read(n);
	for(int i = 0, x, w; i < n; ++i)
	{
		read(x); read(w);
		a[i].l = x - w;
		a[i].r = x + w;
	}
	sort(a, a+n);
	for(int i = 0, last = -INF; i < n; ++i)
		if(a[i].l >= last)
		{
			++ans;
			last = a[i].r;
		}
	printf("%d\n", ans);
	return 0;
}

