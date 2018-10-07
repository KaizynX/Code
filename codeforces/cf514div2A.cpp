#include <bits/stdc++.h>

using namespace std;

int n, L, a, ans;

int main()
{
	scanf("%d%d%d", &n, &L, &a);
	int cur = 0;
	for(int i = 0, t, l; i < n; ++i)
	{
		scanf("%d%d", &t, &l);
		ans += (t-cur)/a;
		cur = t+l;
	}
	ans += (L-cur)/a;
	printf("%d\n", ans);
	return 0;
}
