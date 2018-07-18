#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 6e3 + 7;

int n, m = 1, cnt, ans;
int a[Maxn], son[Maxn], fa[Maxn];
int f[Maxn][2]; // f[][0] not choose f[][1] choose it
bool not_root[Maxn];
int q[Maxn], head, tail;
int u[Maxn], v[Maxn], fir[Maxn], nex[Maxn];

// f[i][0] = max(f[j][0], f[j][1]) j is son of i
// f[i][1] = a[i] + f[j][0]

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a+i);
	while(scanf("%d%d", &v[m], &u[m]) && u[m] && v[m]) // v is son of u
	{
		not_root[v[m]] = true;
		++son[u[m]];
		fa[v[m]] = u[m];
		nex[m] = fir[u[m]];
		fir[u[m]] = m;
		++m;
	}
	
	for(int i = 1; i <= n; ++i)
		if(!son[i])
		{
			q[++tail] = i; ++cnt;
		}
	int cur, num;
	while(cnt)
	{
		num = cnt;
		cnt = 0;
		while(num--)
		{
			cur = q[++head];
			f[cur][1] = a[cur]; // f[cur][0] = 0;
			for(int k = fir[cur]; k; k = nex[k])
			{
				f[cur][0] += max( f[v[k]][1], f[v[k]][0] );
				f[cur][1] += f[v[k]][0];
			}
			if(--son[fa[cur]] == 0)
			{
				q[++tail] = fa[cur];
				++cnt;
			}
		}
	}

	for(int i = 1; i <= n; ++i)
		if(!not_root[i]) ans += max(f[i][0], f[i][1]);
	printf("%d\n", ans);
	return 0;
}
