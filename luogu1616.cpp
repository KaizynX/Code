#include <iostream>
#include <cstdio>

using namespace std;

const int Maxt = 1e5 + 7;
const int Maxm = 1e4 + 7;

int T, M;
int f[Maxt];

int main()
{
	scanf("%d%d", &T, &M);
	for(int i = 0, t, v; i < M; ++i)
	{
		scanf("%d%d", &t, &v);
		for(int j = t; j <= T; ++j)
			f[j] = max(f[j], f[j-t] + v);
	}
	printf("%d\n", f[T]);
	return 0;
}
