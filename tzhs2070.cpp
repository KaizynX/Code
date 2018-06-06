#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e3 + 7;

int n, T;
int s[Maxn];
int f[Maxn]; // f[i] ==> min value in area[1, i]

int main()
{
	scanf("%d%d", &n, &T);
	for(int i = 1, tmp; i <= n; ++i)
	{
		scanf("%d", &tmp);
		s[i] = s[i-1] + tmp;
	}
	for(int i = 1; i <= n; ++i)
	{
		f[i] = (s[i] - T) * (s[i] - T);
		for(int j = 1; j < i; ++j)
		{
			// area[j+1, i] & f[j]
			f[i] = min(f[i], f[j] + (s[i]-s[j]-T)*(s[i]-s[j]-T));
		}
	}
	printf("%d\n", f[n]);
	return 0;
}
