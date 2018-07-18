#include <iostream>
#include <cstdio>

using namespace std;

const int v[] = {1, 5, 10, 50, 100, 500};

int A, c[6], ans;

int main()
{
	for(int i = 0; i < 6; ++i)
		scanf("%d", c+i);
	scanf("%d", &A);
	int k = 5, tmp;
	while(A && k >= 0)
	{
		tmp = min(A/v[k], c[k]);
		ans += tmp;
		A -= v[k] * tmp;
		--k;
		printf("%d %d %d\n", k, A, ans);////////
	}
	printf("%d\n", ans);
	return 0;
}
