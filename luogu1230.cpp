#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int Maxn = 507;

int m, n;
struct Node
{
	int t, w;
	bool operator < (const Node &b) const
	{
		return t == b.t ? w > b.w : t > b.t;
	}
} a[Maxn];

priority_queue<int> q;

int main()
{
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i].t);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i].w);
	sort(a, a+n);
	for(int t = n, cnt = 0; t; --t)
	{
		while(a[cnt].t == t) q.push(a[cnt++].w);
		if(!q.empty()) q.pop();
	}
	while(!q.empty())
	{
		m -= q.top();
		q.pop();
	}
	printf("%d\n", m);
	return 0;
}
