#include <iostream>
#include <cstdio>

using namespace std;

const int Maxt = 1007;
const int Maxw = 40;

int T, W;
int f[Maxw][2];
// after w-1 move under tree 1|2

int main()
{
	scanf("%d%d", &T, &W);
	for(int i = 0, now; i < T; ++i)
	{
		scanf("%d", &now);
		for(int j = W+1; j; --j)
		{
			f[j][0] = max(f[j][0], f[j-1][1]) + (now == 1 ? 1 : 0);
			f[j][1] = max(f[j][1], f[j-1][0]) + (now == 2 ? 1 : 0);
		}
	}
	printf("%d\n", max(f[W+1][0], f[W+1][1]));
	return 0;
}
