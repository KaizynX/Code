#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 2e5+7;

int n, m, d, res;
int da[Maxn];

priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > q;

struct Coffee
{
	int a, id;
	bool operator < (const Coffee &b) const
	{
		return a < b.a;
	}
} c[Maxn];

int main()
{
	scanf("%d%d%d", &n, &m, &d);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &c[i].a), c[i].id = i;
	sort(c+1, c+n+1);
	da[c[1].id] = ++res;
	q.push(make_pair(c[1].a, 1));
	pair<int, int> cur;
	for(int i = 2; i <= n; ++i)
	{
		cur = q.top();
		if(cur.first+d+1 > c[i].a)
		{
			da[c[i].id] = ++res;
			q.push(make_pair(c[i].a, res));
		}
		else
		{
			q.pop();
			da[c[i].id] = cur.second;
			q.push(make_pair(c[i].a, cur.second));
		}
	}
	printf("%d\n", res);
	for(int i = 1; i < n; ++i)
		printf("%d ", da[i]);
	printf("%d\n", da[n]);
	return 0;
}
