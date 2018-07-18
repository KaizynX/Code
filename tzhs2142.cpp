#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 200;

int n, k, ans;

void dfs(int now, int num, int last)
{
	if(n-now < (k-num)*last) return;
	if(num == k)
	{
		if(now == n) ++ans;
		return;
	}
	for(int i = last; i+now <= n; ++i)
		dfs(now+i, num+1, i);
}

int main()
{
	scanf("%d%d", &n, &k);
	dfs(0, 0, 1);
	printf("%d\n", ans);
	return 0;
}
