#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

long long n, m, x_1, y_1, x_2, y_2;


int main()
{
	scanf("%lld%lld%lld%lld%lld%lld", &n, &m, &x_1, &y_1, &x_2, &y_2);
	long long ans = abs(x_1 - x_2) + abs(y_1 - y_2);
	printf("%lld\n", ans);
	return 0;
}
