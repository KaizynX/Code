#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 40;

int n;
int a[Maxn], mid[Maxn][Maxn]; // mid of [l, r]
long long f[Maxn][Maxn];

long long solve(int l, int r)
{
	if(l > r) return 1; // empty tree
	if(l == r) return a[l];
	if(f[l][r]) return f[l][r];
	for(int i = l; i <= r; ++i)
	{
		// take i as mid
		long long tmp = solve(l, i-1) * solve(i+1, r) + a[i];
		if(tmp > f[l][r])
		{
			f[l][r] =  tmp;
			mid[l][r] = i;
		}
	}
	return f[l][r];
}

void pre_print(int l, int r)
{
	if(l > r) return;
	if(l == r)
	{
		printf("%d ", l);
		return;
	}
	printf("%d ", mid[l][r]);
	pre_print(l, mid[l][r] - 1);
	pre_print(mid[l][r] + 1, r);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a+i);
	printf("%lld\n", solve(1, n));
	pre_print(1, n);
	return 0;
}
