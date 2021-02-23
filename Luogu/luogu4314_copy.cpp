/*
 * @Author: Kaizyn
 * @Date: 2021-02-23 19:04:33
 * @LastEditTime: 2021-02-23 19:04:40
 */
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
const int MAXN=110000;
struct SegmentTree
{
	struct Node
	{
		int l, r; bool tag;
		int mx, add, cov;
		int mx_, add_, cov_;
	} tr[4*MAXN];
	#define lc (o<<1)
	#define rc (o<<1|1)
	void pushup(int o)
	{
		tr[o].mx=max(tr[lc].mx, tr[rc].mx);
		tr[o].mx_=max(tr[lc].mx_, tr[rc].mx_);
	}
	void plus(int o, int k, int k_)
	{
		tr[o].mx_=max(tr[o].mx_, tr[o].mx+k_), tr[o].mx+=k;
		if (!tr[o].tag)
			tr[o].add_=max(tr[o].add_, tr[o].add+k_), tr[o].add+=k;
		else tr[o].cov_=max(tr[o].cov_, tr[o].cov+k_), tr[o].cov+=k;
	}
	void cover(int o, int k, int k_)
	{
		tr[o].mx_=max(tr[o].mx_, k_), tr[o].mx=k;
		tr[o].cov_=max(tr[o].cov_, k_), tr[o].cov=k, tr[o].tag=1;
	}
	void pushdown(int o)
	{
		if (tr[o].add)
		{
			plus(lc, tr[o].add, tr[o].add_);
			plus(rc, tr[o].add, tr[o].add_);
			tr[o].add=tr[o].add_=0;
		}
		if (tr[o].tag)
		{
			cover(lc, tr[o].cov, tr[o].cov_);
			cover(rc, tr[o].cov, tr[o].cov_);
			tr[o].tag=0, tr[o].cov_=INT_MIN;
		}
	}
	void build(int o, int l, int r, int* a)
	{
		tr[o].l=l, tr[o].r=r;
		tr[o].add=tr[o].add_=tr[o].tag=0;
		tr[o].cov_=INT_MIN;
		if (l==r) { tr[o].mx=tr[o].mx_=a[l]; return; }
		int mid=l+r>>1;
		build(lc, l, mid, a);
		build(rc, mid+1, r, a);
		pushup(o);
	}
	int queryQ(int o, int l, int r)
	{
		if (tr[o].l>r||tr[o].r<l) return INT_MIN;
		if (l<=tr[o].l&&tr[o].r<=r) return tr[o].mx;
		pushdown(o);
		return max(queryQ(lc, l, r), queryQ(rc, l, r));
	}
	int queryA(int o, int l, int r)
	{
		if (tr[o].l>r||tr[o].r<l) return INT_MIN;
		if (l<=tr[o].l&&tr[o].r<=r) return tr[o].mx_;
		pushdown(o);
		return max(queryA(lc, l, r), queryA(rc, l, r));
	}
	void updateP(int o, int l, int r, int k)
	{
		if (tr[o].l>r||tr[o].r<l) return;
		if (l<=tr[o].l&&tr[o].r<=r) { plus(o, k, k); return; }
		pushdown(o);
		updateP(lc, l, r, k), updateP(rc, l, r, k);
		pushup(o);
	}
	void updateC(int o, int l, int r, int k)
	{
		if (tr[o].l>r||tr[o].r<l) return;
		if (l<=tr[o].l&&tr[o].r<=r) { cover(o, k, k); return; }
		pushdown(o);
		updateC(lc, l, r, k), updateC(rc, l, r, k);
		pushup(o);
	}
	#undef lc
	#undef rc
} sgt;
int a[MAXN];
int main()
{
//	freopen("bzoj3064.in", "r", stdin);
//	freopen("bzoj3064.out", "w", stdout);
	int n, q;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);
	sgt.build(1, 1, n, a);
	scanf("%d", &q);
	while (q--)
	{
		char op[2]; int x, y, z;
		scanf("%s", op);
		switch (op[0])
		{
			case 'Q':
				scanf("%d%d", &x, &y);
				printf("%d\n", sgt.queryQ(1, x, y));
				break;
			case 'A':
				scanf("%d%d", &x, &y);
				printf("%d\n", sgt.queryA(1, x, y));
				break;
			case 'P':
				scanf("%d%d%d", &x, &y, &z);
				sgt.updateP(1, x, y, z);
				break;
			case 'C':
				scanf("%d%d%d", &x, &y, &z);
				sgt.updateC(1, x, y, z);
				break;
		}
	}
	return 0;
}