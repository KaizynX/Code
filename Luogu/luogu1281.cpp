#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 510;
const int INF = 0x3f3f3f3f;

int n, k;
int a[Maxn];

struct Node
{
	int s, t;
} b[Maxn], res[Maxn];

inline bool check(int mid)
{
	int cur = k, cnt = 0;
	b[1].s = 1;
	b[k].t = n;
	for(int i = n; i; --i)
	{
		if(cnt+a[i] > mid)
		{
			b[cur].s = i+1;
			if(--cur < 1) return false;
			b[cur].t = i;
			cnt = a[i];
		}
		else cnt += a[i];
	}
	return true;
}

int main()
{
	int l = INF, r = 1;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", a+i);
		l = min(l, a[i]);
		r += a[i];
	}
	if(n == 1)
	{
		puts("1 1");
		return 0;
	}
	while(l < r)
	{
		int mid = (l+r)>>1;
		if(check(mid))
		{
			memcpy(res+1, b+1, sizeof(Node)*k);
			r = mid;
		}
		else l = mid+1;
	}
	for(int i = 1; i <= k; ++i)
		printf("%d %d\n", res[i].s, res[i].t);
	return 0;
}
