#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 305;

int n, m;
int k[Maxn], s[Maxn], d[Maxn], num[Maxn];
vector<int> child[Maxn];

void init_tree(int cur)
{
	num[cur] = 1; // itself
	for(vector<int>::iterator it = child[cur].begin(); it != child[cur].end(); ++it)
	{
		init_tree(*it);
		num[cur] += num[*it];
	}
}

int dp_tree(int cur, int rest)
{
	if(rest == 0) return 0;
	if(rest == 1) return s[cur];
	// memory search
	if(dp[cur][rest]) return dp[cur][rest];
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d", k+i, s+i);
		child[k[i]].push_back(i);
	}
	init_tree(0);
	printf("%d\n", dp_tree(0, m+1));
	return 0;
}
