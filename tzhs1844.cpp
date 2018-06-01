#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

#define DEBUG

using namespace std;

const int Maxn = 1e+5 + 7;
const int Maxm = 8e6;

int n, p, c, m, maxd;
int u[Maxm], v[Maxm], fir[Maxm], nex[Maxm];
int q_p[Maxn], q_d[Maxn], head, tail;
bool vis[Maxn];

void bfs()
{
	int cur_p, cur_d;
	memset(vis,0,sizeof vis);
	// memset(q,0,sizeof q);
	head = 0;
	tail = 0;
	++tail;
	q_p[tail] = c;
	q_d[tail] = 1;
	vis[c] = true;

	while(head < tail)
	{
		head ++;
		cur_p = q_p[head];
		cur_d = q_d[head];
#ifdef DEBUG
		printf("%d %d\n",cur_p,cur_d);
#endif

		if(cur_d > maxd) maxd = cur_d;

		for(int i = fir[cur_p]; i; i = nex[i])
		{
			if(vis[ v[i] ]) continue;

			++tail;
			q_p[tail] = v[i];
			q_d[tail] = cur_d + 1;
			vis[ v[i] ] = true;
		}
	}
}

inline void connect (int i)
{
	nex[i] = fir[ u[i] ];
	fir[ u[i] ] = i;
}

int main()
{
	scanf("%d%d%d%d",&n,&p,&c,&m);
	// connect two sides
	for(int i = 1; i <= p; ++i)
	{
		scanf("%d%d",u+i,v+i);
		u[i+p] = v[i];
		v[i+p] = u[i];
		connect(i);
		connect(i+p);
	}
#ifdef DEBUG
	for(int i = 1; i <= 2*p; ++i)
		printf("%d %d %d %d\n",u[i],v[i],fir[i],nex[i]);
#endif
	bfs();
	printf("%d\n",maxd + m);
	return 0;
}
