#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn = 1e5 + 7;

int n, c, x[Maxn];

bool judge(int cur)
{
	int cnt = 1;
	for(int i = 1, last = 0; i < n; ++i)
	{
		if(x[i] - x[last] >= cur)
		{
			last = i;
			if(++cnt >= c) return true;
		}
	}
	return false;
}

int main()
{
	int l = 0x3f3f3f3f, r;
	scanf("%d%d", &n, &c);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", x+i);
	}
	sort(x, x+n);
	for(int i = 0; i < n; ++i)
		l = min(x[i]-x[i-1], l);
	r = x[n-1] - x[0];
	while(l < r)
	{
		int mid = (l + r + 1) >> 1;
		if(judge(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}
