#include <bits/stdc++.h>

using namespace std;

int n, d, m, x, y;

int main()
{
	scanf("%d%d%d", &n, &d, &m);
	while(m--)
	{
		scanf("%d%d", &x, &y);
		if(x+y >= d && x+y <= 2*n-d && x-y >= -d && x-y <= d) puts("YES");
		else puts("NO");
	}
	return 0;
}
