#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int Maxn = 1e6 + 7;

int n, ans;

struct Node
{
	int t, v;
	bool operator < (const Node &b) const
	{
		return t > b.t;
	}
} a[Maxn];

priority_queue<int> q;

inline void read(int &);

int main()
{
	read(n);
	for(int i = 0; i < n; ++i)
	{
		read(a[i].t);
		read(a[i].v);
	}
	sort(a, a+n);
	for(int t = a[0].t, cur = 0; t; --t)
	{
		while(t == a[cur].t) q.push(a[cur++].v);
		if(!q.empty())
		{
			ans += q.top();
			q.pop();
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
