#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n,k;

int main()
{
	int cur = 1;
	scanf("%d%d",&n,&k);
	for(int i = 0;i <= k; ++i)
	{
        printf("%d ", cur);
        cur *= n;
	}
	return 0;
}
