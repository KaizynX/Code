#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn = 3e4 + 7;
const int Maxh = 5e3 + 7;

int n, h, ans;
bool used[Maxn];
int tree[Maxn];

struct Node
{
	int b, e, t;
	bool operator < (const Node &nex) const
	{
		return e == nex.e ? b > nex.b : e < nex.e;
	}
} a[Maxh];

inline void add(int i)
{
	for( ; i <= n; i += i & -i) ++tree[i];
}

inline int query(int l, int r)
{
	int res_l = 0, res_r = 0;
	for( ; r; r -= r & -r) res_r += tree[r];
	for(--l; l; l -= l &-l) res_l += tree[l];
	return res_r - res_l;
}

int main()
{
	scanf("%d%d", &n, &h);
	for(int i = 0; i < h; ++i)
		scanf("%d%d%d", &a[i].b, &a[i].e, &a[i].t);
	sort(a, a+h);
	for(int i = 0, cnt; i < h; ++i)
	{
		if((cnt = query(a[i].b, a[i].e)) >= a[i].t) continue;
		for(int j = a[i].e; j >= a[i].b; --j)
			if(!used[j])
			{
				used[j] = true;
				add(j);
				++ans;
				if(++cnt >= a[i].t) break;
			}
	}
	printf("%d\n", ans);
	return 0;
}

