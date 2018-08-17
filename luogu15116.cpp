#include <cstdio>
#include <bitset>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxm = 1e6+7;

int n;
char s[Maxm<<1];
bitset<Maxm> bs, bc;

int main()
{
	scanf("%d", &n);
	bs[0] = bc[0] = 1;
	for(int i = 0, nums, numc; i < n; ++i)
	{
		nums = numc = 0;
		scanf("%s", s);
		for(int i = 0, len = strlen(s); i < len; ++i)
		{
			if(s[i] == 's') nums++;
			if(s[i] == 'c') numc++;
		}
		bs |= bs<<nums;
		bc |= bc<<numc;
	}
	for(int i = Maxm-1; i >= 0; --i)
	{
		if(bs[i] && bc[i])
		{
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}
