#include <bits/stdc++.h>

using namespace std;

long long N, M, K, S;

int main()
{
	cin >> N >> M >> K;
	// S % 0.5 == 0
	if(N*M*2 % K)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	// k >= 2 --> S <= n*m/2
	S = 2*N*M/K;
	for(long long n = max(1ll, (long long)ceil(S/M)); n <= min(N, S); ++n)
	{
		for(long long m = max(1ll, (long long)ceil(S/n)); m <= min(M, S-n+1); ++m)
		{
			if(n*m < S) continue;
			else if(n*m == S)
			{
				printf("0 0\n0 %I64d\n%I64d 0\n", m, n);
				return 0;
			}
			for(long long x = 1; x*x <= n*m-S && x < N; ++x)
			{
				if((n*m-S)%x) continue;
				long long y = (N*M-S)/x;
				if(y >= M) continue;
				printf("0 0\n%I64d %I64d\n%I64d %I64d\n", x, m, n, y);
				return 0;
			}
		}
	}
	return 0;
}
