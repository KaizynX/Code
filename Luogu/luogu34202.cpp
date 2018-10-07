#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e7;

int A, B, num;
long long ans, sum;

inline long long sum_i(int x)
{
	long long res = 0;
	for(int i = 1; i <= x; ++i)
	{
		if(i&1) res -= x/i;
		else res += x/i;
	}
	return res;
}

int main()
{
	scanf("%d%d", &A, &B);
	if(A == B)
	{
		printf("%lld\n", sum_i(A));
		return 0;
	}
	num = B-A+1;
	for(int i = A; i <= B; ++i)
		sum += i;
	for(int i = 1; i <= B; ++i)
	{
		if(i > A) sum -= i-1;
		if(i&1) ans -= (sum/i-num+num/i);
		else ans += (sum/i-num+num/i);
	}
	printf("%lld\n", ans);
	///////
	ans = 0;
	for(int i = A; i <= B; ++i)
		ans += sum_i(i);
	printf("%lld\n", ans);
	return 0;
}
