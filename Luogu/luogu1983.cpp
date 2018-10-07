#include <cstdio>
#include <iostream>
#include <bitset>
#include <vector>
#include <cstring>
#include <queue>

#define DEBUG

using namespace std;

const int Maxn = 1000 + 7;
const int Maxm = 1e6 / 2 + 7;

int n, m, ans;
bitset <Maxn> a[Maxn], b_and,b_xor;
int s[Maxn], t[Maxn];
bool vis[Maxn][Maxn];
int u[Maxm] , v[Maxm], fir[Maxm], nex[Maxm], tot; // u > v
int du[Maxn]; // du[i] <==> how many points bigger than i

inline int getint();
inline void add_edge(int x, int y) // x > y
{
	if(vis[x][y] || vis[y][x]) return;
	++tot;
	u[tot] = x;
	v[tot] = y;
	nex[tot] = fir[x];
	fir[x] = tot;

	++du[y];
	vis[x][y] = vis[y][x] = true;
}

void bfs()
{
	queue<int> q;
	int now_d = 0, nex_d = 0, cnt = 0;
	// num --> the point we visited, we need visit all n points
	int num = 0, now_p, nex_p;
	// there no chance that we push the same point cause du[i] == 0

	// first depth
	for(int i = 1; i <= n; ++i)
	{
		if(!du[i])
		{
			q.push(i);
			++now_d;
			++num;
		}
	}
	++ans;

	while(num < n)
	{
		while(cnt < now_d)
		{
			now_p = q.front();
#ifdef DEBUG
			printf("%d ",now_p);
#endif
			q.pop();

			for(int k = fir[now_p]; k; k = nex[k])
			{
				nex_p = v[k];
				if(--du[nex_p] == 0)
				{
					q.push(nex_p);
					++nex_d;
					++num;
				}
			}
			++cnt; // pop the point we push last depth
		}
		now_d = nex_d;
		nex_d = 0;
		cnt = 0;
		++ans; // every depth
#ifdef DEBUG
		putchar('\n');
#endif
	}
#ifdef DEBUG
	while(!q.empty())
	{
		printf("%d ",q.front());
		q.pop();
	}
	putchar('\n');
#endif
}

int main()
{
	int tmp, cnt;
	memset(vis,0,sizeof vis);
	n = getint();
	m = getint();
	for(int i = 0; i < m; ++ i)
	{
		cnt = getint();
		for(int j = 0; j < cnt; ++ j)
		{
			tmp = getint();
			a[i][tmp] = 1;
			if(j == 0) s[i] = tmp;
			else if(j == cnt - 1) t[i] = tmp;
		}
		// which appear must bigger than those not appear
		vector <int> tmp;
		for(int j = s[i]; j <= t[i]; ++j)
		{
			if(a[i][j]) tmp.push_back(j);
		}
		for(int vi = 0; vi < tmp.size(); ++vi)
			for(int j = s[i]; j <= t[i]; ++j)
				if(!a[i][j]) add_edge(tmp[vi],j);
		/*
		vector <int> tmp;
		for(int j = 1; j <= n; ++j)
			if(a[i][j]) tmp.push_back(j);
		for(int vi = 0; vi < tmp.size(); ++vi)
			for(int j = 1; j <= n; ++j)
				if(!a[i][j]) add_edge(tmp[vi],j);
		*/
	}
	int start,tail; // [start,tail] = a[i] U a[j]
	for(int i = 0; i < m - 1; ++ i)
	{
		for(int j = i + 1; j < m; ++ j)
		
			// if x appear in both
			// x must bigger than which appear once or none
			vector <int> tmp;
			b_and = a[i] & a[j];
			b_xor = a[i] ^ a[j];
			start = max(s[i],s[j]);
			tail  = min(t[i],t[j]);
			// tmp remember which appear once
			// now we not concern about which appear none
			for(int k = start; k <= tail; ++k)
				if(b_xor[k]) tmp.push_back(k);
			// add the relation
			for(int k = start; k <= tail; ++k)
			{
				if(!b_and[k]) continue;
				for(int vi = 0; vi < tmp.size(); ++vi)
					add_edge(k,tmp[vi]);
			}
		}
	}
	bfs();
	printf("%d\n",ans);
	return 0;
}

inline int getint()
{
	int res = 0;
	int c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res;
}
