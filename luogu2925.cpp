#include <iostream>
#include <cstdio>

using namespace std;

const int Maxc = 5e4 + 7;

int C, H;
int f[Maxc];

int main()
{
	scanf("%d%d", &C, &H);
	for(int i = 0, V; i < H; ++i)
	{
		scanf("%d", &V);
		for(int j = C; j >= V; --j)
			if(f[j] != j) f[j] = max(f[j], f[j-V] + V);
		if(f[C] == C) break;
	}
	printf("%d\n", f[C]);
	return 0;
}
