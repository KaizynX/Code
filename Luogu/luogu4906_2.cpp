#include <bits/stdc++.h>

using namespace std;

const int Maxn = 25;

int n, a[Maxn], b[Maxn], vis[1<<21];
typedef pair<int, int> _pair;
queue<_pair> q;

int main()
{
	scanf("%d", &n);
	for(int i = 1, m, x; i <= n; ++i)
	{
		scanf("%d", &m);
		for(int j = 0; j < m; ++j)
		{
			scanf("%d", &x);
			a[i] ^= (1<<x);
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		b[i] ^= a[i];
		b[i] ^= (1<<i);
		for(int j = 1; j <= n; ++j)
			if(a[i]&(1<<j))
				b[i] ^= a[j];
	}
	
	int close = (1<<(n+1))-2;
	_pair cur;
	q.push(make_pair(0, 0));
	vis[0] = 1;
	while(q.size())
	{
		cur = q.front();
		q.pop();
		for(int i = 1, nex; i <= n; ++i)
		{
			nex = cur.first^b[i];
			if(nex == close) return printf("%d\n", cur.second+1)&0;
			if(!vis[nex])
			{
				vis[nex] = 1;
				q.push(make_pair(nex, cur.second+1));
			}
		}
	}
	puts("Change an alarm clock£¬please!");
	return 0;
}
