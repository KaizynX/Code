#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

const int Maxn = 22;
const int Maxm = 4;
const int Maxa = 100;

int n, m;
int a[Maxn];
bitset<2007> b;

inline int cal()
{
	b.reset();
	b[0] = 1;
	for(int i = 1; i <= n; ++i)
	{
		b = b<<a[i] | b;
		b[a[i]] = 1;
	}
	return b.count() - 1;
}

int dfs(int last, int cnt)
{
	if(cnt >= m) return cal();

	int ans = 0;
	for(int i = last + 1, tmp; i <= n; ++i)
	{
		tmp = a[i];
		a[i] = 0;
		ans = max(ans, dfs(i, cnt+1));
		a[i] = tmp;
	}
	return ans;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", a+i);
	printf("%d\n", dfs(0, 0));
	return 0;
}
