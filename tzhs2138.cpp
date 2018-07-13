#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e5 + 7;

int n, m, ans;

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0, a, cnt = 0; i < n; ++i)
	{
		scanf("%d", &a);
		if(cnt + a <= m) cnt += a;
		else
		{
			cnt = a;
			++ans;
		}
	}
	printf("%d\n", ++ans);
	return 0;
}
