#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn = 3e4 + 7;
const int Maxh = 5e3 + 7;

int n, h, ans;
bool used[Maxn];

struct Node
{
	int b, e, t;
	bool operator < (const Node &nex) const
	{
		return e == nex.e ? b > nex.b : e < nex.e;
	}
} a[Maxh];

int main()
{
	scanf("%d%d", &n, &h);
	for(int i = 0; i < h; ++i)
		scanf("%d%d%d", &a[i].b, &a[i].e, &a[i].t);
	sort(a, a+h);
	for(int i = 0, cnt; i < h; ++i)
	{
		cnt = 0;
		for(int j = a[i].b; j <= a[i].e; ++j)
			if(used[j]) ++cnt;
		if(cnt >= a[i].t) continue;
		for(int j = a[i].e; j >= a[i].b; --j)
			if(!used[j])
			{
				used[j] = true;
				++ans;
				if(++cnt >= a[i].t) break;
			}
	}
	printf("%d\n", ans);
	return 0;
}
