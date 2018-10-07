#include <cstdio>
#include <bitset>
#include <iostream>

using namespace std;

const int Maxn = 60;
const int Maxk = 207;
const int Maxv = 2e6+7;

int n, k;
int a[Maxn];
bitset<Maxv> b[2], res;

int main()
{
	scanf("%d%d", &k, &n);
	for(int i = 0; i < n; ++i) scanf("%d", a+i);
	b[1][0] = 1;
	for(int i = 0; i < k; ++i)
	{
		b[i&1].reset();
		for(int j = 0; j < n; ++j)
			b[i&1] |= b[(i+1)&1] << a[j];
		res |= b[i&1];
	}
	for(int i = 1; i < Maxv; ++i)
		if(~res[i])
		{
			printf("%d\n", i-1);
			break;
		}
	return 0;
}
