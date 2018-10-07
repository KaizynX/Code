#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 5e4+7;
const int Maxm = 2e5+7;

int n, m, k, x, y, disx, disy, res;
int is_k[Maxn], dis[Maxn];
int ver[Maxm], w[Maxm], fir[Maxn], nex[Maxm], tot;

template <typename T> inline void read(T &);
inline void add_edge(int u, int v, int z)
{
	ver[++tot] = v; w[tot] = z; nex[tot] = fir[u]; fir[u] = tot;
}

void dijiskra(int S)
{
	typedef pair<int, int> pot;
	priority_queue<pot, vector<pot>, greater<pot> > q;
	memset(dis, 0x7f, sizeof dis);
	dis[S] = 0;
	pot cur;
	q.push(make_pair(0, S));
	while(q.size())
	{
		cur = q.top();
		q.pop();
		int now = cur.second;
		if(dis[now] < cur.first) continue;
		for(int i = fir[now], to, tmp; i; i = nex[i])
		{
			to = ver[i];
			if(is_k[to]) continue;
			tmp = cur.first+w[i];
			if(tmp < dis[to])
			{
				dis[to] = tmp;
				q.push(make_pair(tmp, to));
				if(S == x && to == y) return;
			}
		}
	}
}

int main()
{
	// scanf("%d%d%d", &n, &m, &k);
	read(n); read(m); read(k);
	for(int i = 1, tmp; i <= k; ++i)
	{
		// scanf("%d", &tmp);
		read(tmp);
		is_k[tmp] = 1;
	}
	for(int i = 1, u, v, z; i <= m; ++i)
	{
		// scanf("%d%d%d", &u, &v, &z);
		read(u); read(v); read(z);
		add_edge(u, v, z);
		add_edge(v, u, z);
	}
	// scanf("%d%d", &x, &y);
	read(x); read(y);
	dijiskra(1);
	disx = dis[x];
	disy = dis[y];
	dijiskra(x);
	// luoen walk to x to y || y to x
	res = min(disx, disy)+dis[y];
	memset(is_k, 0, sizeof is_k);
	dijiskra(1);
	// two walk to different
	res = min(res, min(max(disx, dis[y]), max(disy, dis[x])));
	disx = dis[x];
	disy = dis[y];
	dijiskra(x);
	res = min(res, min(disx, disy)+dis[y]);
	printf("%d\n", res);
	return 0;
}

template <typename T> inline void read(T &x)
{
    char c;
    while((c=getchar()) < '0' || c > '9');
    x = c-'0';
    while((c=getchar()) >= '0' && c <= '9') x = (x<<1)+(x<<3) + c-'0';
}
