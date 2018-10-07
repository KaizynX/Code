#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int T;
long long A, B, a, b, res;

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld%lld", &A, &B);
		a = ceil(sqrt(A));
		b = floor(sqrt(B));
		if(a > b) res = 0;
		// the odd number between a and b
		else res = ((b-a+1)>>1)+(a&1 && b&1);
		puts(res&1 ? "Yes" : "No");
	}
	return 0;
}
