#include <bits/stdc++.h>

using namespace std;

const int Maxn = 4e3+7;

int n;
long long ans;
int A[Maxn], B[Maxn], C[Maxn], D[Maxn];
int sum[Maxn*Maxn], cnt;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	for(int i = 1; i <= n; ++i) scanf("%d", B+i);
	for(int i = 1; i <= n; ++i) scanf("%d", C+i);
	for(int i = 1; i <= n; ++i) scanf("%d", D+i);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			sum[++cnt] = C[i]+D[j];
	sort(sum+1, sum+cnt+1);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			int cur = A[i]+B[j];
			ans += upper_bound(sum+1, sum+cnt+1, -cur)
				  -lower_bound(sum+1, sum+cnt+1, -cur);
		}
	printf("%I64d\n", ans);
	return 0;
}
