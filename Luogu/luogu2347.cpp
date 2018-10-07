#include <iostream>
#include <cstdio>

using namespace std;

const int Maxm = 1e3 + 7;
const int w[] = {1, 2, 3, 5, 10, 20};

int f[Maxm];

int main()
{
	for(int i = 0, c; i < 6; ++i)
	{
		scanf("%d", &c);
		for(int j = 0; j < c; ++j)
			for(int v = 1000; v >= w[i]; --v)
				f[v] = max(f[v], f[v-w[i]] + w[i]);
	}
	int ans = 0;
	for(int i = 1; i <= 1000; ++i) if(f[i] == i) ans++;
	printf("Total=%d\n", ans);
	return 0;
}
