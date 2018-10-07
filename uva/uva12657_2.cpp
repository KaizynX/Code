#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e5 + 7;

int n, m, T;
int L[Maxn], R[Maxn];

inline void link(int x, int y) { R[x] = y; L[y] = x; }

int main()
{
	int ope, x, y;
	long long ans;
	bool is_reverse;
	while( scanf("%d%d",&n,&m) == 2)
	{
		for(int i = 1; i <= n; ++i) { L[i] = i-1; R[i] = i+1; }
		R[0] = 1; L[n+1] = n;
		is_reverse = false;
		ans = 0;

		while(m--)
		{
			scanf("%d",&ope);
			if(ope == 4) { is_reverse = !is_reverse; continue; }
			scanf("%d%d",&x,&y);
			if(ope == 3 && R[y] == x) swap(x,y);
			if(ope == 1 && x == L[y]) continue;
			if(ope == 2 && x == R[y]) continue;

			int x_l = L[x], x_r = R[x], y_l = L[y], y_r = R[y];
			if(ope == 1) { link(y_l,x); link(x,y); link(x_l,x_r); }
			else if(ope == 2) { link(y,x); link(x,y_r); link(x_l,x_r); }
			else // ope == 3
			{
				if(R[x] == y) { link(x_l,y); link(x,y_r); link(y,x); }      // x y
				else if(L[x] == y) { link(y_l,x); link(y,x_r); link(x,y); } // y x
				else { link(x_l,y); link(y,x_r); link(y_l,x); link(x,y_r); }
			}
		}
		for(int i = 1, cur = R[0]; i <= n; ++i, cur = R[cur])
			if(i & 1) ans += cur;
		if(is_reverse && n % 2 == 0) ans =(long long)n*(n+1)/2 - ans;
		printf("Case %d: %lld\n",++T,ans);
	}
	return 0;
}
