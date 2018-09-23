#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e2+7;

int n, m, sum, maxa, a;

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a);
		maxa = max(a, maxa);
		sum += a;
	}
	printf("%d %d\n", max(maxa, (sum+m)/n+((sum+m)%n != 0)), maxa+m);
	return 0;
}
