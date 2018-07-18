#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e5 + 7;
const int INF = 0x7fffffff;

int n, m, a[Maxn];

bool check(int mid)
{
	int cnt = 0, cur = 0;
	for(int i = 1; i <= n; ++i)
	{
		cur += a[i];
		if(cur > mid)
		{
			cur = a[i];
			if(++cnt > m) return false;
		}
	}
	if(cur) ++cnt;
	return cnt <= m;
}

int main()
{
	int l = 0, r = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", a+i);
		l = max(l, a[i]);
		r += a[i];
	}
	while(l < r)
	{
		int mid = (l+r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}
