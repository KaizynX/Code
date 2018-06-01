#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn = 5e3 + 7;

int n;
int a[Maxn], cot[Maxn], cnt;

int main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	scanf("%d",&n);
	for(int i = 0; i < n; ++i) scanf("%d",a+i);
	// we could reverse it, put it from top to bottom
	// and refer to Greedy Algorithm
	// every time we search from the former cottage
	// i < j --> cot[i] > cot[j]
	// if we could put it to i & j
	// put on i must take more value
	sort(a,a+n);
	for(int i = 0, j; i < n; ++i)
	{
		for(j = 1; j <= cnt; ++j)
			if(a[i] >= cot[j]) break;
		++cot[j];
		if(j > cnt) ++cnt;
	}
	printf("%d\n",cnt);
	return 0;
}
