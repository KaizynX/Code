#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define DEBUG

using namespace std;

const int Maxn = 507;

int m, n;
struct Node
{
	int t, w;
	bool operator < (const Node &b) const
	{
		return w < b.w;
	}
} a[Maxn];
priority_queue<Node> q;

bool cmp(const Node &x, const Node &y)
{
	return x.t == y.t ? x.w > y.w : x.t > y.t;
}

int main()
{
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i].t);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i].w);
	sort(a, a+n, cmp);
	for(int t = n, cnt = 0; t; --t)
	{
		while(a[cnt].t == t) q.push(a[cnt++]);
		/*
		while(!q.empty() && q.top().t > t)
		{
#ifdef DEBUG
			printf("%d %d\n", q.top().t, q.top().w);
#endif
			m -= q.top().w;
			q.pop();
		}
		*/
#ifdef DEBUG
		if(!q.empty()) printf("pop:%d %d\n", q.top().t, q.top().w);
#endif
		if(!q.empty()) q.pop();
	}
	while(!q.empty())
	{
		m -= q.top().w;
		q.pop();
	}
	printf("%d\n", m);
	return 0;
}
