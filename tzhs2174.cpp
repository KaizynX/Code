#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e5 + 7;
const int INF = 0x7fffffff;

int n, k, a[Maxn];

inline bool check(int mid)
{
	int minh = a[1], maxh = a[1], res = 0;
	for(int i = 2; i <= n; ++i)
	{
		minh = min(minh, a[i]);
		maxh = max(maxh, a[i]);
		if(maxh - minh > mid)
		{
			if(++res >= k) return false;
			minh = a[i];
			maxh = a[i];
		}
		else if(i == n)
			++res;
	}
	return res <= k;
}

int main()
{
	int l = 0, r, minh = INF, maxh = 1;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", a+i);
		minh = min(a[i], minh);
		maxh = max(a[i], maxh);
	}
	r = maxh - minh;
	while(l < r)
	{
		int mid = (l+r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}
