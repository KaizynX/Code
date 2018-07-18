#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e3 + 7;

int n;
int f[Maxn], b[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n/2; ++i)
		for(int j = 2; i * j <= n; ++j)
			f[i * j] += i;
	for(int i = 2; i <= n; ++i)
		for(int v = n; v >= i; --v)
			b[v] = max(b[v], b[v-i] + f[i]);
	printf("%d\n", b[n]);
	return 0;
}
