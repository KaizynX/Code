#include <bits/stdc++.h>

using namespace std;

int n, ans;

inline bool prime(int x)
{
	if(x == 1) return false;
	for(int i = 2; i*i <= x; ++i)
		if(x%i == 0) return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(prime(__gcd(i, j))) ans++;
	printf("%d\n", ans);
	return 0;
}
