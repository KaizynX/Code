#include <cstdio>
#include <iostream>

using namespace std;

int n, a, maxa, mina;

int main()
{
	scanf("%d%d", &n, &a);
	maxa = mina = a;
	for(int i = 2; i <= n; ++i)
	{
		scanf("%d", &a);
		maxa = max(a, maxa);
		mina = min(a, mina);
	}
	printf("%d\n", maxa-mina+1-n);
	return 0;
}
