#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e5+7;

int n, m;
int a[Maxn];

inline bool check(int now)
{
	int cur = 0, cnt = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(cur+a[i] > now)
		{
			cur = a[i];
			++cnt;
		}
		else cur += a[i];
	}
	if(cur) ++cnt;
	return cnt <= m;
}

int main()
{
	int l = 0, r = 0, mid;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", a+i);
		l = max(l, a[i]);
		r += a[i];
	}
	if(n == 0)
	{
		puts("0");
		return 0;
	}
	else if(n == 1)
	{
		printf("%d\n", l);
		return 0;
	}
	if(m == 1)
	{
		printf("%d\n", r);
		return 0;
	}
	while(l < r)
	{
		mid = (l+r)>>1;
		if(check(mid)) r = mid;
		else l = mid+1;
	}
	printf("%d\n", l);
	return 0;
}
