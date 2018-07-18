#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int Maxn = 8+2;
const int P[] = {2,3,5,7};

int n;

bool is_prime(int a)
{
	for(int i=2;i<=sqrt(a)+0.5;++i)
		if(a%i==0)return 0;
	return 1;
}

void solve(int now,int cur)
{
	if(cur>n)
	{
		printf("%d\n",now);
		return;
	}
	int next;
	for(int i=1;i<=9;i+=2)
	{
		next=now*10+i;
		if(is_prime(next)==1)
			solve(next,cur+1);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<4;++i)
	{
		solve(P[i],2);
	}
	return 0;
}
