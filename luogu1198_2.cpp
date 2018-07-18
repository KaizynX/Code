#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 2e5 + 7;

int M, D, n, cnt;
int tr[Maxn*4]; // storage the max num of area
long long a[Maxn];
char op[Maxn];

inline long long read();
void update_tree(int, int, int, int, int);
int query_tree(int, int, int, int, int);

int main()
{
	long long t = 0;
	M = read(); D = read();
	for(int i = 0; i < M; ++i)
	{
		op[i] = getchar();
		a[i] = read();
		if(op[i] == 'A') ++n;
	}
	for(int i = 0; i < M; ++i)
	{
		if(op[i] == 'A')
		{
			t = (a[i] + t) % D; // now t <= D <= 2e9
			update_tree(++cnt, (int)t, 1, 1, n);
		}
		else printf("%d\n",query_tree(cnt-(int)a[i]+1, cnt, 1, 1, n));
	}
	return 0;
}

void update_tree(int x, int v, int i, int l, int r)
{
	if(l == x && r == x) { tr[i] = v; return; }
	int mid = (l + r) >> 1;
	if(x <= mid) update_tree(x, v, i*2, l, mid);
	else update_tree(x, v, i*2+1, mid+1, r);
	tr[i] = max(tr[i*2], tr[i*2+1]);
}

int query_tree(int x, int y, int i, int l, int r)
{
	if(x <= l && y >= r) return tr[i];
	int mid = (l + r) >> 1;
	if(y <= mid) return query_tree(x, y, i*2, l, mid);
	else if(x > mid) return query_tree(x, y, i*2+1, mid+1, r);
	else return max( query_tree(x, y, i*2, l, mid), query_tree(x, y, i*2, mid+1, r));
}

inline long long read()
{
	char c; int tag = 1;
	while((c=getchar()) < '0' || c > '9') if(c == '-') tag = -1;
	long long res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = (res<<1)+(res<<3) + c-'0';
	return res * tag;
}
