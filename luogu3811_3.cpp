#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 3e6+7;

int n, p, inv[Maxn];

int main()
{
	scanf("%d%d", &n, &p);
	inv[1] = 1;
	puts("1");
	for(int i = 2; i <= n; ++i)
	{
		inv[i] = (long long)(p-p/i)*inv[p%i]%p;
		printf("%d\n", inv[i]);
	}
	return 0;
}
