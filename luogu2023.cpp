#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e5 + 7;

int N, M, P;
int a[Maxn];

struct Tree
{
	int l, r;
	long long sum, mul, add;
	Tree(): l(0), r(0), sum(0), mul(1), add(0) {}
} tr[Maxn << 2];

inline void read(int&);
void build_tree(int, int, int);
void update_tree(int, int, int, int, int);
int query_tree(int, int, int);
inline void push_down(int);
inline int ls(int i) { return i << 1; }
inline int rs(int i) { return i << 1 | 1; }

int main()
{
	read(N); read(P);
	for(int i = 1; i <= N; ++i) read(a[i]);
	build_tree(1, 1, N);
	read(M);
	for(int i = 0, op, x, y, c; i < M; ++i)
	{
		read(op); read(x); read(y);
		if(op == 3) printf("%d\n", query_tree(1, x ,y));
		else
		{
			read(c);
			update_tree(1, x, y, c%P, op);
		}
	}
	return 0;
}


void build_tree(int i, int l, int r)
{
	tr[i].l = l; tr[i].r = r;
	if(l == r) { tr[i].sum = a[l]; return; }
	int mid = (l + r) >> 1;
	build_tree(ls(i), l, mid);
	build_tree(rs(i), mid+1, r);
	tr[i].sum = (tr[ls(i)].sum + tr[rs(i)].sum) % P;
}

void update_tree(int i, int l, int r, int c, int op)
{
	if(l <= tr[i].l && r >= tr[i].r)
	{
		if(op == 1)
		{
			tr[i].sum = tr[i].sum * c % P;
			tr[i].mul = tr[i].mul * c % P;
			tr[i].add = tr[i].add * c % P;
		}
		else
		{
			tr[i].sum = (tr[i].sum + c * (tr[i].r - tr[i].l + 1)) % P;
			tr[i].add = (tr[i].add + c) % P;
		}
		return ;
	}

	push_down(i);
	int mid = (tr[i].l + tr[i].r) >> 1;
	if(l <= mid) update_tree(ls(i), l, r, c, op);
	if(r >  mid) update_tree(rs(i), l, r, c, op);
	tr[i].sum = (tr[ls(i)].sum + tr[rs(i)].sum) % P;
}

int query_tree(int i, int l, int r)
{
	if(l <= tr[i].l && r >= tr[i].r) return static_cast<int>(tr[i].sum);
	push_down(i);
	int mid = (tr[i].l + tr[i].r) >> 1, res = 0;
	if(l <= mid) res = (res + query_tree(ls(i), l, r)) % P;
	if(r >  mid) res = (res + query_tree(rs(i), l, r)) % P;
	return res;
}

inline void push_down(int i)
{
	int len = tr[i].r - tr[i].l + 1;
	tr[ls(i)].sum = (tr[ls(i)].sum * tr[i].mul + tr[i].add * ((len+1)>>1)) % P;
	tr[rs(i)].sum = (tr[rs(i)].sum * tr[i].mul + tr[i].add * (len >> 1)  ) % P;
	tr[ls(i)].mul = tr[ls(i)].mul * tr[i].mul % P;
	tr[rs(i)].mul = tr[rs(i)].mul * tr[i].mul % P;
	tr[ls(i)].add = (tr[ls(i)].add * tr[i].mul + tr[i].add) % P;
	tr[rs(i)].add = (tr[rs(i)].add * tr[i].mul + tr[i].add) % P;
	tr[i].mul = 1;
	tr[i].add = 0;
}

inline void read(int &res)
{
	char c;
	while((c=getchar()) < '0' || c > '9');
	res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = (res<<1)+(res<<3) + c-'0';
}
