#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 2e5+7;

int n, m, d, res, cnt;
int fa[Maxn], da[Maxn];

struct Coffee
{
	int a, id;
	bool operator < (const Coffee &b) const
	{
		return a < b.a;
	}
} c[Maxn];

int getf(int s) { return fa[s] == s ? s : fa[s] = getf(fa[s]); }

int main()
{
	scanf("%d%d%d", &n, &m, &d);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &c[i].a), fa[i] = i, c[i].id = i;
	sort(c+1, c+n+1);
	while(cnt < n)
	{
		int cur = getf(1), last;
		da[c[cur].id] = ++res;
		if(++cnt == n) break;
		last = cur;
		cur = fa[cur] = getf(cur+1);
		while(cur)
		{
			while(cur && c[last].a+d >= c[cur].a)
				cur = getf(cur+1);
			if(!cur) break;
			da[c[cur].id] = res;
			if(++cnt == n) break;
			last = cur;
			cur = fa[cur] = getf(cur+1);
		}
	}
	printf("%d\n", res);
	for(int i = 1; i < n; ++i)
		printf("%d ", da[i]);
	printf("%d\n", da[n]);
	return 0;
}
