#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e6 + 7;

int n, P;
int c[Maxn];

int main()
{
	scanf("%d", &n, &P);
	bool flag = true;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", c+i);
		if(c[i] > 0) flag = false;
	}
	if(flag)
	{
		puts("TerriblePlace ");
		return 0;
	}
	else puts("2");
	return 0;
}
