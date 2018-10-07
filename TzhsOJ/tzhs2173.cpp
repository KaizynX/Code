#include <iostream>
#include <cstdio>

using namespace std;

const int Mo = 1e9+7;
const int Maxn = 1e3+7;

int n;
int f[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= i/2; ++j)
			f[i] += f[j];
		f[i]++;
		// printf("%d %d\n", i, f[i]);
	}
	printf("%d\n", f[n] % Mo);
	return 0;
}
