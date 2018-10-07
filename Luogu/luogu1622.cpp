#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxp = 1e3+7;
const int Maxq = 1e2+7;
const int INF = 0x3f3f3f3f;

int p, q;
int a[Maxq];
int f[Maxq][Maxq];

int main()
{
	scanf("%d%d", &p, &q);
	for(int i = 1; i <= q; ++i)
		scanf("%d", a+i);
	sort(a+1, a+q+1);
	a[0] = 0; a[q+1] = p+1;
	for(int len = 2; len <= q+1; ++len)
	{
		for(int i = 0, j; i+len <= q+1; ++i)
		{
			j = i+len;
			f[i][j] = INF;
			for(int k = i+1; k < j; ++k)
			{
				// delete a[k] & a[i] & a[j]
				f[i][j] = min(f[i][j], f[i][k]+f[k][j]+a[j]-a[i]-2);
			}
		}
	}
	printf("%d\n", f[0][q+1]);
	return 0;
}
