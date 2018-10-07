#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e6+666;
const int Maxp = 1e5;

int n;
int prime[Maxp], cnt;
bool check[Maxn+6];
int res[Maxn+6];

inline void init()
{
	check[1] = true;
	for(int i = 2; i <= Maxn; ++i)
	{
		if(!check[i])
		{
			prime[++cnt] = i;
			res[i] = 0;
			for(int j = prime[cnt-1]+1, tmp = i-prime[cnt-1]; j < prime[cnt]; ++j)
				res[j] = tmp;
		}
		for(int j = 1; j <= cnt && i*prime[j] <= Maxn; ++j)
		{
			check[i*prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
}

int main()
{
	init();
	while(scanf("%d", &n) != EOF)
		printf("%d\n", res[n]);
	return 0;
}
