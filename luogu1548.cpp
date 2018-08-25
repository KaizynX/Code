#include <cstdio>
#include <iostream>

using namespace std;

int n, m, sum, zheng;

inline int add(int x)
{
	return (x+1)*x/2;
}

int main()
{
	scanf("%d%d", &n, &m);
	sum = add(n)*add(m);
	for(int i = 1; i <= min(n, m); ++i)
		zheng += (n-i+1)*(m-i+1);
	printf("%d %d\n", zheng, sum-zheng);
	return 0;
}
