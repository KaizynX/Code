#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int Maxn = 1e5+7;

int n, m, f[Maxn], du[Maxn];
vector<int> e[Maxn];
queue<int> q;

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0, x, y; i < m; ++i)
	{
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		du[y]++;
	}
	for(int i = 1; i <= n; ++i)
		if(!du[i])
		{
			q.push(i);
			f[i] = 1;
		}
	while(q.size())
	{
		int cur = q.front();
		q.pop();
		for(vector<int>::iterator it = e[cur].begin(); it != e[cur].end(); ++it)
		{
			if(--du[*it] == 0)
			{
				f[*it] = f[cur]+1;
				q.push(*it);
			}
		}
	}
	for(int i = 1; i <= n; ++i)
		printf("%d\n", f[i]);
	return 0;
}
