#include <cstdio>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
// WA 80
const int Maxn = 2000000000;
const int Maxk = 1000+5;

int n,k;
int power_2[32];

void init()
{
	power_2[0]=1;
	for(int i=1;i<=30;++i)
	{
		power_2[i]=power_2[i-1]*2;
	}
}

main()
{
	int pos;
	scanf("%d%d",&n,&k);
	init();
	while(k--)
	{
		pos=upper_bound( power_2 , power_2+30 , n )-power_2;
		//find fist power_2[pos] > n
		pos--;
		// power_2[pos] <= n
		n-=power_2[pos];
	}
	printf("%d\n",power_2[pos]-n);
	return 0;
}
