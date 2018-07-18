#include <iostream>
#include <cstdio>

using namespace std;

int n, ans;

int main()
{
	int cnt = 1;
	cin >> n;
	while(n)
	{
		if(n&1)
		{
			ans += cnt-1;
		}
		n >>= 1;
		cnt <<= 1;
	}
	printf("%d\n", ans);
	return 0;
}
