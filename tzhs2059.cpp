#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#define DEBUG

using namespace std;

const int Maxn = 100 + 7;
const int Maxt = 1000 + 7;

int n,T,ans;

struct pool
{
	int start, less, next = 0;
	int sum, time;
} p[Maxn];

struct node
{
	int val, num;
	bool operator < (const node &b) const
	{
		return val < b.val;
	}
}tmp;

priority_queue <node> q;

int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; ++ i)
		scanf("%d",&p[i].start);
	for(int i = 1; i <= n; ++ i)
		scanf("%d",&p[i].less);
	for(int i = 1; i < n; ++ i)
		scanf("%d",&p[i].next);
	scanf("%d",&T);

	int t = T, cur = n, fish = 0;
	for(int i = 1; i < n; ++ i)
		t -= p[i].next;
	for(int i = 1; i <= n; ++ i)
	{
		tmp.val = p[i].start;
		tmp.num = i;
		q.push(tmp);
	}
	while(cur)
	{
		t += p[cur].next + p[cur].time;
		fish -= p[cur].sum;
		while(t > 0)
		{
			if(q.empty()) break;
			tmp = q.top();
#ifdef DEBUG
			cout << tmp.val << ' ' << tmp.num << endl;
#endif
			q.pop();
			if(tmp.num > cur) continue;
			fish += tmp.val;
			--t;
			p[tmp.num].sum += tmp.val;
			p[tmp.num].time ++;
			if(fish > ans) ans = fish;
			tmp.val -= p[tmp.num].less;
			if(tmp.val <= 0) continue;
			q.push(tmp);
		}

		cur--;
	}
	
	printf("%d\n",ans);

	return 0;
}
