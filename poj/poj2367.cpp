#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 107;

int n;
int f[Maxn];
vector<int> s[Maxn];

inline void tuopu()
{
	queue<int> q;
	for(int i = 1; i <= n; ++i)
		if(!f[i]) q.push(i);
	while(q.size())
	{
		int cur = q.front();
		q.pop();
		printf("%d ", cur);
		for(int i = 0; i < s[cur].size(); ++i)
			if(--f[s[cur][i]] == 0) q.push(s[cur][i]);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1, x; i <= n; ++i)
		while(scanf("%d", &x) && x != 0)
		{
			f[x]++;
			s[i].push_back(x);
		}
	tuopu();
	return 0;
}
