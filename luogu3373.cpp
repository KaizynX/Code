#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e5 + 7;

int N, M, P;
long long a[Maxn];

struct Tree
{
	int l, r;
	long long sum, add, mul;
	Tree():l(0), r(0), sum(0), add(0), mul(1){}
} tr[Maxn << 2];

template <typename T> inline void read(T &);
inline int ls(int s) { return s << 1; }
inline int rs(int s) { return s << 1 | 1; }
inline void push_down(int);
void build_tree(int ,int ,int);
void update_tree(int ,int ,int, int, int);
long long query_tree(int ,int, int);

int main()
{
	read(N); read(M); read(P);
	for(int i = 1; i <= N; ++i) read(a[i]);
	build_tree(1, 1, N);
	for(int i = 0, op, x, y; i < M; ++i)
	{
		read(op); read(x); read(y);
		if(op == 3) printf("%lld\n", query_tree(1, x, y));
		else
		{
			long long k; read(k);
			update_tree(1, x, y, static_cast<int>(k%P), op);
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

void update_tree(int i, int l, int r, int k, int op)
{
	if(l <= tr[i].l && r >= tr[i].r)
	{
		if(op == 1)
		{
			tr[i].sum = tr[i].sum * k % P;
			tr[i].mul = tr[i].mul * k % P;
			tr[i].add = tr[i].add * k % P;
		}
		else 
		{
			tr[i].sum = ((tr[i].r - tr[i].l + 1) * k % P + tr[i].sum) % P;
			tr[i].add = (tr[i].add + k) % P;
		}
		return;
	}

	push_down(i);
	int mid = (tr[i].l + tr[i].r) >> 1;
	if(l <= mid) update_tree(ls(i), l, r, k, op);
	if(r >  mid) update_tree(rs(i), l, r, k, op);
	tr[i].sum = (tr[ls(i)].sum + tr[rs(i)].sum) % P;
}

long long query_tree(int i, int l, int r)
{
	if(l <= tr[i].l && r >= tr[i].r) return tr[i].sum % P;
	push_down(i);
	int mid = (tr[i].l + tr[i].r) >> 1;
	long long res = 0;
	if(l <= mid) res += query_tree(ls(i), l, r);
	if(r >  mid) res += query_tree(rs(i), l, r);
	return res % P;
}

inline void push_down(int i)
{
	int len = tr[i].r - tr[i].l + 1;
	tr[ls(i)].sum = (tr[ls(i)].sum * tr[i].mul % P + tr[i].add * ((len+1)>>1) % P) %P;
	tr[rs(i)].sum = (tr[rs(i)].sum * tr[i].mul % P + tr[i].add * (len >> 1)   % P) %P;
	tr[ls(i)].mul = tr[ls(i)].mul * tr[i].mul % P;
	tr[rs(i)].mul = tr[rs(i)].mul * tr[i].mul % P;
	tr[ls(i)].add = (tr[ls(i)].add * tr[i].mul % P + tr[i].add) % P;
	tr[rs(i)].add = (tr[rs(i)].add * tr[i].mul % P + tr[i].add) % P;
	tr[i].mul = 1;
	tr[i].add = 0;
}

template <typename T> inline void read(T &res)
{
	char c; int tag = 1;
	while((c=getchar()) < '0' || c > '9') if(c == '-') tag = -1;
	res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = (res<<1)+(res<<3) + c-'0';
	res *= tag;
}
