#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 300 + 7;
const int Maxm = 50000 + 7;

int n, m, cnt, maxw;
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
} e[Maxm];

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) fa[i] = i;
	for(int i = 0; i < m; ++ i )
	{
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	sort(e,e + m);
	int fu, fv;
	for(int i = 0; i < m; ++ i)
	{
		fu = getf(e[i].u);
		fv = getf(e[i].v);
		if(fu != fv)
		{
			fa[fu] = fv;
			// sort
			maxw = e[i].w;
			if(++cnt >= n - 1) break;
		}
	}
	cout << cnt << " " << maxw << endl;
	return 0;
}

