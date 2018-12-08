#include <bits/stdc++.h>

using namespace std;

const int Maxn = 4e3+7;

int n;
long long ans;
int A[Maxn], B[Maxn], C[Maxn], D[Maxn];
int sum1[Maxn*Maxn], sum2[Maxn*Maxn], cnt1, cnt2;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	for(int i = 1; i <= n; ++i) scanf("%d", B+i);
	for(int i = 1; i <= n; ++i) scanf("%d", C+i);
	for(int i = 1; i <= n; ++i) scanf("%d", D+i);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			sum1[++cnt1] = A[i]+B[j];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			sum2[++cnt2] = C[i]+D[j];
	sort(sum1+1, sum1+cnt1+1);
	sort(sum2+1, sum2+cnt2+1);
	for(int i = 1; i <= cnt1; ++i)
	{
		ans += upper_bound(sum2+1, sum2+cnt2+1, -sum1[i])
			  -lower_bound(sum2+1, sum2+cnt2+1, -sum1[i]);
	}
	printf("%I64d\n", ans);
	return 0;
}
