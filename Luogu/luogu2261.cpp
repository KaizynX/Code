#include <bits/stdc++.h>
#define DEBUG

using namespace std;

int n, k;
long long ans;

int main()
{
	scanf("%d%d", &n, &k);
	ans = 1ll*n*k;
	int edge = sqrt(k);
	// k/i (i[1, edge]) >= floor(k/edge)
	for(int i = 1; i <= min(n, edge); ++i)
		ans -= k/i*i;
	// floor(k/j) = i, i < floor(k/edge)
	for(int i = 1, l, r; i < k/edge; ++i)
	{
		// floor(k/j) == i (j <= n)
		// j [floor(k/(i+1))+1, floor(k/i)]
		l = k/(i+1)+1; r = k/i; 
		r = min(r, n);
		if(l > r) continue;
		ans -= 1ll*(r-l+1)*(l+r)/2*i;
	}
	printf("%lld\n", ans);
	return 0;
}
