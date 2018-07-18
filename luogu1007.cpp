#include <iostream>
#include <cstdio>

using namespace std;

int L, N;
int minp = 5e5, maxp;

int main()
{
	scanf("%d%d", &L, &N);
	if(!N)
	{
		printf("0 0\n");
		return 0;
	}
	for(int i = 0, tmp; i < N; ++i)
	{
		scanf("%d", &tmp);
		if(tmp < minp) minp = tmp;
		if(tmp > maxp) maxp = tmp;
	}
	printf("%d %d\n", minp, maxp); //////
	if(N == 1) printf("%d %d\n", min(minp, L+1-minp), max(minp, L+1-minp));
	else printf("%d %d\n", max(minp, L+1-maxp), max(L+1-minp, maxp));
	return 0;
}
