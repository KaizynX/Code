#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const int Maxn = 2e3;
const int Maxm = 1e4;

int s, t;
int prime[Maxn], cnt;
pair<int, int> q[Maxm];
int head, tail;
bool vis[Maxm];
vector<int> m[Maxm];

inline bool judge(int x, int y)
{
	int a, b, cnt = 0;
	while(x)
	{
		a = x % 10;
		b = y % 10;
		if(a != b)
		{
			if(++cnt > 1) return false;
		}
		x /= 10;
		y /= 10;
	}
	return cnt == 1;
}

int main()
{
	scanf("%d%d", &s, &t);
	// init prime
	for(int i = 1001; i <= 9999; i += 2)
	{
		bool flag = true;
		for(int j = 2, edge = sqrt(i)+0.5; j <= edge; ++j)
		{
			if(i % j == 0)
			{
				flag = false;
				break;
			}
		}
		if(flag) prime[++cnt] = i;
	}
	// init map
	for(int i = 1; i <= cnt; ++i)
	{
		for(int j = 1; j <= cnt; ++j)
		{
			if(i == j) continue;
			if(judge(prime[i], prime[j]))
			{
				m[prime[i]].push_back(prime[j]);
				m[prime[j]].push_back(prime[i]);
			}
		}
	}
	// bfs
	q[++tail] = make_pair(s, 0);
	vis[s] = true;
	pair<int, int> cur;
	while(head < tail)
	{
		cur = q[++head];
		// printf("%d %d\n", cur.first, cur.second);
		for(unsigned i = 0, edge = m[cur.first].size(); i < edge; ++i)
		{
			if(vis[m[cur.first][i]]) continue;
			if(m[cur.first][i] == t)
			{
				printf("%d\n", cur.second + 1);
				return 0;
			}
			vis[m[cur.first][i]] = true;
			q[++tail] = make_pair(m[cur.first][i], cur.second+1);
		}
	}
	puts("Impossible");
	return 0;
}
