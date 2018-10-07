#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define DEBUG

using namespace std;

int n, m, x_1, y_1, x_2, y_2;
long long ans;

int main()
{
	scanf("%d%d%d%d%d%d", &n, &m, &x_1, &y_1, &x_2, &y_2);
	if(abs(x_1 - x_2) == n) 
	{
		ans = n + min(y_1 + y_2, 2*m - y_1 - y_2);
		printf("%d\n", min(y_1 + y_2, 2*m - y_1 - y_2) );
	}
	else if(abs(y_1 - y_2) == m) 
	{
		ans = m + min(x_1 + x_2, 2*n - x_1 - x_2);
		printf("%d\n", min(x_1 + x_2, 2*n - x_1 - x_2) );
	}
	else ans = abs(x_1 - x_2) + abs(y_1 - y_2);
	printf("%lld\n", ans);
	return 0;
}

