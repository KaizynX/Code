#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 107;

int n, tot, cnt, ans;
int fa[Maxn];

int getf(int s)
{
	return s == fa[s] ? s : fa[s] = getf(fa[s]);
}

struct E
{
	int u,v,w;
	bool operator < (const E &b) const
	{
		return w < b.w;
	}
} e[Maxn * Maxn / 2];

inline void add_edge(int u, int v, int w)
{
	++tot;
	e[tot].u = u;
	e[tot].v = v;
	e[tot].w = w;
}

int main()
{
	int tmp, fu, fv;
	cin >> n;
	for(int i = 0; i < n; ++ i)
	{
		fa[i] = i;

		for(int j = 0; j < n; ++ j)
		{
			cin >> tmp;
			if(i < j) 
				add_edge(i,j,tmp);
		}
	}
	sort(e+1,e+tot+1);
	for(int i = 1; i <= tot; ++ i)
	{
		fu = getf(e[i].u);
		fv = getf(e[i].v);
		if(fu != fv)
		{
			fa[fu] = fv;
			ans += e[i].w;
			if(++cnt >= n - 1) break;
		}
	}
	cout << ans << endl;
	return 0;
}
