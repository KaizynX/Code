#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 5e5 + 7;
const int INF = 0x3f3f3f3f;

int N, S;
int t[Maxn], f[Maxn];
int dp[Maxn];

int main()
{
	scanf("%d%d", &N, &S);
	for(int i = 1, ti, fi; i <= N; ++i)
	{
		scanf("%d%d", &ti, &fi);
		t[i] = t[i-1] + ti;
		f[i] = f[i-1] + fi;
	}
	for(int i = 1; i <= N; ++i)
	{
		dp[i] = INF;
		for(int j = 1; j <= i; ++j)
			dp[i] = min(dp[i], dp[j-1] + S*(f[N]-f[j-1]) + t[i]*(f[i]-f[j-1]));
	}
	printf("%d\n", dp[N]);
	return 0;
}
