#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, ans;

inline bool judge(int l1, int l2, int l3)
{
	int tmp[3] = {l1, l2, l3};
	sort(tmp, tmp + 3);
	return tmp[0] + tmp[1] > tmp[2];
}

int main()
{
	scanf("%d", &n);
	for(int l1 = 1; l1 <= n-2; ++l1)
	{
		for(int l2 = l1, l3; l1 + l2 < n; ++l2)
		{
			l3 = n - l1 - l2;
			if(l3 < l2) break;
			if(judge(l1, l2, l3))
			{
				// printf("%d %d %d\n", l1, l2, l3);
				++ans;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
