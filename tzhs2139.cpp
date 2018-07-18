#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn = 1e6 + 7;

int n, ans = 1;

struct Node
{
	int a, b;
	bool operator < (const Node &nex) const
	{
		return b == nex.b ? a < nex.a : b < nex.b;
	}
} c[Maxn];

inline void read(int &);

int main()
{
	// freopen("segment10.in", "r", stdin);
	read(n);
	for(int i = 0; i < n; ++i) 
	{
		read(c[i].a);
		read(c[i].b);
	}
	sort(c, c+n);
	for(int i = 1, last = c[0].b; i < n; ++i)
	{
		if(c[i].a >= last)
		{
			++ans;
			last = c[i].b;
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
