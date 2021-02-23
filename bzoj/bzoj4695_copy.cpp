/*
 * @Author: Kaizyn
 * @Date: 2021-02-22 18:57:18
 * @LastEditTime: 2021-02-22 19:50:10
 */
#include <cassert>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN=550000;
const int INF=1E9;
int read()
{
	int x=0, w=0; char ch=0;
	while (!isdigit(ch)) w|=ch=='-', ch=getchar();
	while (isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48), ch=getchar();
	return w?-x:x;
}
struct SegmentTree
{
	struct Node
	{
		int l, r;
		int mn1, mn2, cmn, mx1, mx2, cmx; ll sum;
		int add1, add2, add3;
	} tr[4*MAXN];
	#define lc (o<<1)
	#define rc (o<<1|1)
	void pushup(int o)
	{
		tr[o].sum=tr[lc].sum+tr[rc].sum;
		if (tr[lc].mn1==tr[rc].mn1)
		{
			tr[o].mn1=tr[lc].mn1;
			tr[o].mn2=min(tr[lc].mn2, tr[rc].mn2);
			tr[o].cmn=tr[lc].cmn+tr[rc].cmn;
		}
		else if (tr[lc].mn1<tr[rc].mn1)
		{
			tr[o].mn1=tr[lc].mn1;
			tr[o].mn2=min(tr[lc].mn2, tr[rc].mn1);
			tr[o].cmn=tr[lc].cmn;
		}
		else
		{
			tr[o].mn1=tr[rc].mn1;
			tr[o].mn2=min(tr[lc].mn1, tr[rc].mn2);
			tr[o].cmn=tr[rc].cmn;
		}
		if (tr[lc].mx1==tr[rc].mx1)
		{
			tr[o].mx1=tr[lc].mx1;
			tr[o].mx2=max(tr[lc].mx2, tr[rc].mx2);
			tr[o].cmx=tr[lc].cmx+tr[rc].cmx;
		}
		else if (tr[lc].mx1>tr[rc].mx1)
		{
			tr[o].mx1=tr[lc].mx1;
			tr[o].mx2=max(tr[lc].mx2, tr[rc].mx1);
			tr[o].cmx=tr[lc].cmx;
		}
		else
		{
			tr[o].mx1=tr[rc].mx1;
			tr[o].mx2=max(tr[lc].mx1, tr[rc].mx2);
			tr[o].cmx=tr[rc].cmx;
		}
	}
	void update(int o, int k1, int k2, int k3)
	{
		if (tr[o].mn1==tr[o].mx1)
		{
			if (k1==k3) k1=k2; else k2=k1;
			tr[o].sum+=1ll*k1*tr[o].cmn;
		}
		else tr[o].sum+=1ll*k1*tr[o].cmn+1ll*k2*tr[o].cmx
		    +1ll*k3*(tr[o].r-tr[o].l+1-tr[o].cmn-tr[o].cmx);
		if (tr[o].mn2==tr[o].mx1) tr[o].mn2+=k2;
		else if (tr[o].mn2!=INF) tr[o].mn2+=k3;
		if (tr[o].mx2==tr[o].mn1) tr[o].mx2+=k1;
		else if (tr[o].mx2!=-INF) tr[o].mx2+=k3;
		tr[o].mn1+=k1, tr[o].mx1+=k2;
		tr[o].add1+=k1, tr[o].add2+=k2, tr[o].add3+=k3;
	}
	void pushdown(int o)
	{
		int mn=min(tr[lc].mn1, tr[rc].mn1);
		int mx=max(tr[lc].mx1, tr[rc].mx1);
		update(lc, tr[lc].mn1==mn?tr[o].add1:tr[o].add3,
		    tr[lc].mx1==mx?tr[o].add2:tr[o].add3, tr[o].add3);
		update(rc, tr[rc].mn1==mn?tr[o].add1:tr[o].add3,
		    tr[rc].mx1==mx?tr[o].add2:tr[o].add3, tr[o].add3);
		tr[o].add1=tr[o].add2=tr[o].add3=0;
	}
	void build(int o, int l, int r, int* a)
	{
		tr[o].l=l, tr[o].r=r;
		tr[o].add1=tr[o].add2=tr[o].add3=0;
		if (l==r)
		{
			tr[o].sum=tr[o].mn1=tr[o].mx1=a[l];
			tr[o].mn2=INF, tr[o].mx2=-INF;
			tr[o].cmn=tr[o].cmx=1;
			return;
		}
		int mid=l+r>>1;
		build(lc, l, mid, a);
		build(rc, mid+1, r, a);
		pushup(o);
	}
	void modify1(int o, int l, int r, int k)
	{
		if (tr[o].l>r||tr[o].r<l) return;
		if (l<=tr[o].l&&tr[o].r<=r)
			{ update(o, k, k, k); return; }
		pushdown(o);
		modify1(lc, l, r, k), modify1(rc, l, r, k);
		pushup(o);
	}
	void modify2(int o, int l, int r, int k)
	{
		if (tr[o].l>r||tr[o].r<l||k<=tr[o].mn1) return;
		if (l<=tr[o].l&&tr[o].r<=r&&k<tr[o].mn2)
			{ update(o, k-tr[o].mn1, 0, 0); return; }
		pushdown(o);
		modify2(lc, l, r, k), modify2(rc, l, r, k);
		pushup(o);
	}
	void modify3(int o, int l, int r, int k)
	{
		if (tr[o].l>r||tr[o].r<l||k>=tr[o].mx1) return;
		if (l<=tr[o].l&&tr[o].r<=r&&k>tr[o].mx2)
			{ update(o, 0, k-tr[o].mx1, 0); return; }
		pushdown(o);
		modify3(lc, l, r, k), modify3(rc, l, r, k);
		pushup(o);
	}
	ll query4(int o, int l, int r)
	{
		if (tr[o].l>r||tr[o].r<l) return 0;
		if (l<=tr[o].l&&tr[o].r<=r) return tr[o].sum;
		pushdown(o);
		return query4(lc, l, r)+query4(rc, l, r);
	}
	int query5(int o, int l, int r)
	{
		if (tr[o].l>r||tr[o].r<l) return -INF;
		if (l<=tr[o].l&&tr[o].r<=r) return tr[o].mx1;
		pushdown(o);
		return max(query5(lc, l, r), query5(rc, l, r));
	}
	int query6(int o, int l, int r)
	{
		if (tr[o].l>r||tr[o].r<l) return INF;
		if (l<=tr[o].l&&tr[o].r<=r) return tr[o].mn1;
		pushdown(o);
		return min(query6(lc, l, r), query6(rc, l, r));
	}
	#undef lc
	#undef rc
} sgt;
int a[MAXN];
int main()
{
//	freopen("bzoj4695.in", "r", stdin);
//	freopen("bzoj4695.out", "w", stdout);
	int n, m;
	n=read();
	for (int i=1; i<=n; i++) a[i]=read();
	sgt.build(1, 1, n, a);
	m=read();
	while (m--)
	{
		int op=read(), l, r, k;
		switch (op)
		{
			case 1:
				l=read(), r=read(), k=read();
				sgt.modify1(1, l, r, k);
				break;
			case 2:
				l=read(), r=read(), k=read();
				sgt.modify2(1, l, r, k);
				break;
			case 3:
				l=read(), r=read(), k=read();
				sgt.modify3(1, l, r, k);
				break;
			case 4:
				l=read(), r=read();
				printf("%lld\n", sgt.query4(1, l, r));
				break;
			case 5:
				l=read(), r=read();
				printf("%d\n", sgt.query5(1, l, r));
				break;
			case 6:
				l=read(), r=read();
				printf("%d\n", sgt.query6(1, l, r));
				break;
		}
	}
	return 0;
}