#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 30;

int n, t, m, ans;
int a[Maxn], b[Maxn];

void dfs(int song, int bag, int num)
{
	if(song > n)
	{
		ans = max(ans, num);
		return;
	}
	// choose it
	if(t-b[bag] >= a[song]) // put it int b[bag]
	{
		b[bag] += a[song];
		dfs(song+1, bag, num+1);
		b[bag] -= a[song];
	}
	else if(bag+1 <= m && t >= a[song])// put it in b[bag+1]
	{
		b[bag+1] += a[song];
		dfs(song+1, bag+1, num+1);
		b[bag+1] -= a[song];
	}
	// not choose it
	dfs(song+1, bag, num);
}

int main()
{
	scanf("%d%d%d", &n, &t, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a+i);
	dfs(1, 1, 0);
	printf("%d\n", ans);
	return 0;
}
