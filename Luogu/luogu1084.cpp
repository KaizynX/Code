#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 5e4+7;

/* army[]     in place i the num of army
 * rs[]       the son of root(1)
 * drs[]      the dis of rs[] to root
 * rt[]       the root(rs[]) of a leaf
 * has_army[] is the i has army
 * not_ok[]   is rs[] all sons ok
 */
int n, m, army[Maxn];
int rs[Maxn], rs_num, drs[Maxn], rt[Maxn];
int lg2[Maxn], fa[Maxn][20], dep[Maxn];
long long dis[Maxn][20], l, r;
int ver[Maxn<<1], w[Maxn<<1], fir[Maxn], nex[Maxn<<1], tot;
int has_army[Maxn], not_ok[Maxn];

// the army who can walk to root and has rest time
struct Army
{
	int num, from;
	long long rest;
	Army(){}
	Army(int n, int f, long long r) : num(n), from(f), rest(r) {}
	bool operator < (const Army &b) const { return rest < b.rest; }
};

// the rs[] left , need army
struct Rootson
{
	int id, ds;
	Rootson(){}
	Rootson(int i, int d) : id(i), ds(d) {}
	bool operator < (const Rootson &b) const { return ds < b.ds; }
};

vector<Army> ra;
vector<Rootson> rts;

template <typename T> inline void read(T &);
template <typename T> inline void clear(T &);
inline void add_edge(int, int, int);
inline void build_tree(int, int);
inline bool check_tree(int);

int main()
{
	read(n);
	for(int i = 2; i <= n; ++i) lg2[i] = lg2[i>>1]+1;
	for(int i = 1, u, v, z; i < n; ++i)
	{
		read(u); read(v); read(z);
		add_edge(u, v, z);
		add_edge(v, u, z);
	}
	// init fa[][], dep[], dis[][], rt[]
	build_tree(1, 0);
	read(m);
	// nums of army less than nums of rs
	if(rs_num > m)
	{
		puts("-1");
		return 0;
	}
	for(int i = 0, id; i < m; ++i)
	{
		read(id);
		army[id]++;
	}

	r <<= 1;
	while(l < r)
	{
		long long mid = (l+r)>>1, nowd = 0;
		memset(has_army, 0, sizeof(int)*(n+1));
		memset(not_ok, 0, sizeof(int)*(n+1));
		clear(ra); clear(rts);
		for(int i = 2, cur, k; i <= n; ++i)
		{
			// analyse every army
			if(!army[i]) continue;
			cur = i;
			// from i to 1 in time(mid)
			while(cur != 1)
			{
				k = lg2[dep[cur]];
				if(nowd+dis[cur][k] > mid) break;
				nowd += dis[cur][k];
				cur = fa[cur][k];
			}
			// can't up to root in time(mid)
			if(cur != 1) has_army[cur] = 1;
			else ra.push_back(Army(army[i], rt[i], mid-nowd));
		}
		// check if rs[] all son is ok
		check_tree(1);
		for(int i = 0; i < ra.size(); ++i)
			// the army had better stay at it's initial rs
			if(not_ok[ra[i].from] && ra[i].rest < drs[ra[i].from])
			{
				not_ok[ra[i].from] = 0;
				// delete it
				if(--ra[i].num == 0)
				{
					ra.erase(ra.begin()+i);
					i--;
				}
			}
		// add the rest rs[] need the army
		for(int i = 1; i <= rs_num; ++i)
			if(not_ok[rs[i]]) rts.push_back(Rootson(rs[i], drs[rs[i]]));
		sort(rts.begin(), rts.end());
		sort(ra.begin(), ra.end());
		int flag = 0;
		for(int i = 0; i < rts.size(); ++i)
		{
			flag = 0;
			// choose an army to go
			for(int j = 0; j < ra.size(); ++j)
			{
				if(!ra[j].num || ra[j].rest < rts[i].ds) continue;
				flag = 1;
				ra[j].num--;
				break;
			}
			// not find one
			if(!flag) break;
		}
		if(!flag) l = mid+1;
		else r = mid;
	}
	printf("%lld\n", l);
	return 0;
}

inline bool check_tree(int cur)
{
	// the cur has army || [cur has son(cur is not leaf) && it's sons all ok]
	if(has_army[cur]) return true;
	int flag = 1, cnt = 0;
	for(int i = fir[cur], to; i; i = nex[i])
	{
		to = ver[i];
		if(ver[i] == fa[cur][0]) continue;
		cnt++;
		flag &= check_tree(to);
	}
	flag &= cnt;
	if(!flag) not_ok[cur] = 1;
	return false;
}

inline void build_tree(int cur,int root)
{
	for(int i = 1; i <= lg2[dep[cur]]; ++i)
	{
		fa[cur][i] = fa[fa[cur][i-1]][i-1];
		dis[cur][i] = dis[cur][i-1]+dis[fa[cur][i-1]][i-1];
		r = max(dis[cur][i], r);
	}
	if(cur != 1) rt[cur] = root;
	for(int i = fir[cur], to; i; i = nex[i])
	{
		to = ver[i];
		if(ver[i] == fa[cur][0]) continue;
		// root's son
		if(cur == 1)
		{
			rs[++rs_num] = root = to;
			drs[to] = w[i];
		}
		fa[to][0] = cur;
		dep[to] = dep[cur]+1;
		dis[to][0] = w[i];
		build_tree(to, root);
	}
}

inline void add_edge(int u, int v, int z)
{
	ver[++tot] = v; w[tot] = z; nex[tot] = fir[u]; fir[u] = tot;
}

template <typename T> inline void read(T &x)
{
	char c;
	while((c=getchar()) < '0' || c > '9');
	x = c-'0';
	while((c=getchar()) >= '0' && c <= '9')
		x = (x<<1)+(x<<3) + c-'0';
}

template <typename T> inline void clear(T &x)
{
	T tmp;
	swap(x, tmp);
}
