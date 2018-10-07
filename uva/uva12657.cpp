#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e5 + 7;

struct Node
{
	int v, l ,r;
	Node():v(0),l(0),r(0){}
} a[Maxn];

int n, m, T;
long long ans;

inline void init(int);
inline void move_left(int,int); // move x to y's left
inline void move_right(int,int);

int main()
{
	bool is_reverse;
	while(scanf("%d%d",&n,&m) == 2)
	{
		init(n);
		is_reverse = false;
		ans = 0;
		for(int i = 0, ope, x, y; i < m; ++i)
		{
			scanf("%d",&ope);
			if(ope == 4) { is_reverse = !is_reverse; continue; }
			scanf("%d%d",&x,&y);
			if(ope == 3) { swap(a[x].v,a[y].v); continue; }
			if((!is_reverse && ope == 1) || (is_reverse && ope == 2))
			{
				if(a[x].r != y) move_left(x,y);
			}
			else
			{
				if(a[y].r != x) move_right(x,y);
			}
		}
		if(!is_reverse)
		{
			for(int i = a[0].r, cnt = 1; i != n+1; ++cnt, i = a[i].r)
				if(cnt & 1) ans += a[i].v;
		}
		else 
		{
			for(int i = a[n+1].l, cnt = 1; i != 0; ++cnt, i = a[i].l)
				if(cnt & 1) ans += a[i].v;
		}
		printf("Case %d: %lld\n",++T,ans);
	}
	return 0;
}

inline void move_left(int x, int y)
{
	int x_l = a[x].l, x_r = a[x].r, y_l = a[y].l;
	// delete x from former place
	a[x_l].r = x_r; a[x_r].l = x_l;
	// put x between y_l and y
	a[x].l = y_l; a[x].r = y;
	a[y_l].r = x; a[y].l = x;
}

inline void move_right(int x, int y)
{
	int x_l = a[x].l, x_r = a[x].r, y_r = a[y].r;
	a[x_l].r = x_r; a[x_r].l = x_l;
	a[x].l = y; a[x].r = y_r;
	a[y_r].l = x; a[y].r = x;
}

inline void init(int num)
{
	for(int i = 1; i <= num; ++i)
	{
		a[i].v = i;
		a[i].l = i-1; //  0  refers to head
		a[i].r = i+1; // n+1 refers to tail
	}
	a[0].r = 1;
	a[num+1].l = num;
}
