#include <bits/stdc++.h>

using namespace std;

struct Heap
{
	static const int Maxn = 1e6+7;

	int a[Maxn], sz;

	Heap(){ sz = 0; memset(a, 0, sizeof a); }

	inline int size() { return sz; }
	inline void push(int x) { a[++sz] = x; swift_up(sz); }
	inline int top() { return a[1]; }
	inline void pop() { swap(a[1], a[sz--]); swift_down(1); }
	inline void swift_up(int p)
	{
		int cur = p;
		while(cur > 1 && a[cur] < a[cur>>1])
		{
			swap(a[cur], a[cur>>1]);
			cur >>= 1;
		}
	}
	inline void swift_down(int p)
	{
		int cur = p, l, r, s;
		while(true)
		{
			l = cur<<1;
			r = cur<<1|1;
			if(l > sz) break;
			if(r > sz || a[l] <= a[r]) s = l;
			else s = r;
			if(a[cur] > a[s])
			{
				swap(a[cur], a[s]);
				cur = s;
			}
			else break;
		}
	}
} h;

int n;

inline void read(int &x)
{
	char c; int tag = 1;
	while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
	x = c-'0';
	while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
	x *= tag;
}

inline void write(int x)
{
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x/10);
	putchar(x%10+'0');
}

int main()
{
	read(n);
	for(int i = 1, op, x; i <= n; ++i)
	{
		read(op);
		if(op == 1) read(x), h.push(x);
		else if(op == 2) write(h.top()), putchar('\n');
		else h.pop();
	}
	return 0;
}
