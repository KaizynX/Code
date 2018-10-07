#include <iostream>
#include <cstdio>

using namespace std;

const int v[] = {1, 5, 10, 50, 100, 500};

int A, c[6], ans;

void dfs(int k, int rest, int num)
{
	if(k == 0)
	{
		ans = min(ans, num + rest);
		return;
	}
	if(num >= ans) return;
	for(int i = min(min(c[k], rest/v[k]), ans-num); i >= 0; --i)
	{
		if(rest == v[k]*i)
		{
			ans = min(ans, num + i);
			return;
		}
		dfs(k-1, rest - v[k]*i, num + i);
	}
}

int main()
{
	for(int i = 0; i < 6; ++i)
		scanf("%d", c+i);
	scanf("%d", &A);
	ans = A;
	dfs(5, A, 0);
	printf("%d\n", ans);
	return 0;
}
