#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 150007;

int n, ans;
int a[Maxn][2];

inline int gcd(int a, int b)
{
	int tmp;
	while(b)
	{
		tmp = a;
		a = b;
		b = tmp%b;
	}
	return a;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i][0], &a[i][1]);
	if(n == 1) 
	{
		printf("%d\n", a[1][0]);
		return 0;
	}
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			ans = max(ans, gcd(a[1][i], a[2][j]));
	for(int i = 3; i <= n; ++i)
	{
		ans = max(gcd(ans, a[i][0]), gcd(ans, a[i][1]));
		if(ans == 1) break;
	}
	printf("%d\n", ans == 1 ? -1 : ans);
	return 0;
}
