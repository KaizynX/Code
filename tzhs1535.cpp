#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int Maxn = 30;

int n, h, cur, ans;
int f[Maxn], d[Maxn], t[Maxn];
int cnt[Maxn], sum[Maxn];

struct Node
{
	int v, num;
	Node(){}
	Node(int v, int num):v(v), num(num) {}

	bool operator < (const Node &b) const
	{
		return v == b.v ? num > b.num : v < b.v;
	}
} tmp;

priority_queue<Node> q;

int main()
{
	scanf("%d%d", &n, &h);
	h *= 12;
	for(int i = 1; i <= n; ++i) 
	{
		scanf("%d", f+i);
		q.push(Node(f[i], i));
	}
	for(int i = 1; i <= n; ++i) scanf("%d", d+i);
	for(int i = 1; i < n; ++i) 
	{
		scanf("%d", t+i);
		h -= t[i];
	}
	for(int i = n; i; --i) // in pool i
	{
		cur -= sum[i+1];
		h += cnt[i+1];
		// back one pool
		h += t[i];

		while(h > 0)
		{
			if(q.empty()) break;

			tmp = q.top();
			q.pop();
			if(tmp.num > i) continue; // can't reach this
			// catch this one
			--h;
			cur += tmp.v;
			// set
			sum[tmp.num] += tmp.v;
			++cnt[tmp.num];
			// update
			tmp.v -= d[tmp.num];
			if(tmp.v > 0) q.push(tmp);
		}
		ans = max(ans, cur);
	}
	printf("%d\n", ans);
	return 0;
}
