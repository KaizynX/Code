#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 2e5 + 7;
const int INF = 2e9 + 7;

template <typename T> inline void read(T &);

int M, D, n, cnt;
char op[Maxn];
long long t;
long long a[Maxn], tr[Maxn<<2];

void update_tree(int, long long, int, int, int);
long long query_tree(int, int, int, int, int);
inline int ls(int s) { return s << 1; }
inline int rs(int s) { return s << 1 | 1; }

int main()
{
	read(M); read(D);
	for(int i = 0; i < M; ++i)
	{
		cin >> op[i]; read(a[i]);
		if(op[i] == 'A') ++n;
	}
	for(int i = 0; i < M; ++i)
	{
		// a[i] may < 0
		if(op[i] == 'A') update_tree(++cnt, (t+a[i])%D, 1, n, 1);
		else printf("%lld\n", t = query_tree(cnt-a[i]+1, cnt, 1, n, 1));
	}
	return 0;
}

void update_tree(int x, long long v, int l, int r, int i)
{
	if(l == x && r == x) { tr[i] = v; return; }
	int mid = (l + r) >> 1;
	if(x <= mid) update_tree(x, v, l, mid, ls(i));
	else update_tree(x, v, mid+1, r, rs(i));
	tr[i] = max(tr[ls(i)], tr[rs(i)]);
}
long long query_tree(int q_l, int q_r, int l, int r, int i)
{
	if(q_l <= l && q_r >= r) return tr[i];
	int mid = (l + r) >> 1;
	long long res = -INF;
	if(q_l <= mid) res = max(res, query_tree(q_l, q_r, l, mid, ls(i)));
	if(q_r >  mid) res = max(res, query_tree(q_l, q_r, mid+1, r, rs(i)));
	return res;
}

template <typename T> inline void read(T &res)
{
	char c; int tag = 1;
	while((c=getchar()) < '0' || c > '9') if(c == '-') tag = -1;
	res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = (res<<1)+(res<<3) + c-'0';
	res *= tag;
}
