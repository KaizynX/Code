#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int Maxn = 2e5 + 7;

int n, ans;
struct Node
{
	int l, r;
	bool operator < (const Node &b) const
	{
		return l == b.l ? r < b.r : l < b.l;
	}
} a[Maxn];

priority_queue<int, vector<int>, greater<int> > q;

// template <typename T> inline void read(T &);

int main()
{
	scanf("%d", &n); // read(n);
	for(int i = 0, x, w; i < n; ++i)
	{
		// abs(x1 - x2) >= w1 + w2
		// x1 > x2 ==> x1 - w1 >= x2 + w2
		// x1 < x2 ==> x1 + w1 <= x2 - w2
		scanf("%d%d", &x, &w); // read(x); read(w);
		a[i].l = x - w;
		a[i].r = x + w;
	}
	sort(a, a+n);
	for(int i = 0; i < n; ++i)
	{
		while(!q.empty() && a[i].l > q.top())
		{
#ifdef DEBUG
			printf("%d\n", q.top());
#endif
			q.pop();
		}
		q.push(a[i].r);
		if(q.size() > ans) ans = q.size();
	}
	printf("%d\n", ans);
	return 0;
}
/*******************
template <typename T> inline void read(T &res)
{
	char c; int tag = 1;
	while((c=getchar()) < '0' || c > '9') if(c == '-') tag = -1;
	res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = (res<<1)+(res<<3) + c-'0';
	res *= tag;
}
*******************/
