#include <bits/stdc++.h>

using namespace std;

int n;
int res[10];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= 9; ++i)
		res[i] = res[i-1]+111;
	printf("%d\n", *lower_bound(res, res+10, n));
	return 0;
}
