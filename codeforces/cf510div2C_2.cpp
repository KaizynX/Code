#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 2e5+7;

// 00 1+ 2-
int n, cnt[3], pos[3], step;
pair<int, int> a[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i].first);
		a[i].second = i;
		if(a[i].first == 0) cnt[0]++;
		else if(a[i].first > 0) cnt[1]++;
		else cnt[2]++;
	}
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; ++i)
	{
		if(a[i].first == 0 && !pos[0]) pos[0] = i;
		else if(a[i].first > 0 && !pos[1]) pos[1] = i;
		else if(a[i].first < 0 && !pos[2]) pos[2] = i;
	}

	while(step < n-1 && cnt[0] > 1)
	{
		printf("1 %d %d\n", a[pos[0]].second, a[pos[0]+1].second);
		pos[0]++; cnt[0]--; step++;
	}
	// now cnt[0] <= 1
	if(step < n-1 && cnt[2]&1)
	{
		if(cnt[0])
		{
			printf("1 %d %d\n", a[pos[0]].second, a[pos[2]+cnt[2]-1].second);
			cnt[2]--; step++;
			if(step < n-1)
			{
				printf("2 %d\n", a[pos[0]].second);
				cnt[0]--; step++;
			}
		}
		else
		{
			printf("2 %d\n", a[pos[2]+cnt[2]-1].second);
			cnt[2]--; step++;
		}
	}
	// now cnt[2]&1 == 0
	if(step < n-1 && cnt[0])
	{
		printf("2 %d\n", a[pos[0]].second);
		cnt[0]--; step++;
	}
	// now cnt[0] == 0
	while(step < n-1 && cnt[2] > 1)
	{
		printf("1 %d %d\n", a[pos[2]].second, a[pos[2]+1].second);
		pos[2]++; cnt[2]--; step++;
	}
	// now cnt[2] <= 1
	while(step < n-1 && cnt[1] > 1)
	{
		printf("1 %d %d\n", a[pos[1]].second, a[pos[1]+1].second);
		pos[1]++; cnt[1]--; step++;
	}
	// now cnt[0] == 0, cnt[1] <= 1, cnt[2] <= 1
	if(step < n-1)
		printf("1 %d %d\n", a[pos[1]].second, a[pos[2]].second);
	return 0;
}
