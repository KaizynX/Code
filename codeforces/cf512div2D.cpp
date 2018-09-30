#include <bits/stdc++.h>

using namespace std;

long long n, m, k, S;

int main()
{
	cin >> n >> m >> k;
	// S % 0.5 == 0
	if(n*m*2 % k)
	{
		puts("NO");
		return 0;
	}
	// k >= 2 --> S <= n*m/2
	S = 2*n*m/k;
	for(long long i = n; i; --i)
	{
		if(S%i) continue;
		if(S/i > m) break;
		printf("YES\n0 0\n%lld 0\n0 %lld\n", i, S/i);
		break;
	}
	return 0;
}
