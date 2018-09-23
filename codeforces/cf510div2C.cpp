#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 2e5+7;

// 00 +1 -2

int n, cnt, a[Maxn];
int num[3], pos = 1;
int q[3][Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", a+i);
		if(a[i] == 0) q[0][++num[0]] = i;
		else if(a[i] > 0) q[1][++num[1]] = i;
		else
		{
			q[2][++num[2]] = i;
			// put the max- to q[2][1]
			if(num[2] != 1 && a[q[2][1]] < a[i])
				swap(q[2][1], q[2][num[2]]);
		}
	}
	if(num[2]&1 && num[0])
	{
		while(cnt+1 <= n-1 && num[2] > 1)
		{
			printf("1 %d %d\n", q[2][num[2]], q[2][num[2]-1]);
			cnt++;
			num[2]--;
		}
		while(cnt+1 <= n-1 && num[0] > 1)
		{
			printf("1 %d %d\n", q[0][num[0]], q[0][num[0]-1]);
			cnt++;
			num[0]--;
		}
		if(cnt+1 <= n-1)
		{
			printf("1 %d %d\n", q[2][1], q[0][1]);
			cnt++;
			num[2]--;
		}
		if(cnt+1 <= n-1)
		{
			printf("2 %d\n", q[0][1]);
			cnt++;
			num[0]--;
		}
	}
	else if(num[0])
	{
		while(cnt+1 <= n-1 && num[0] > 1)
		{
			printf("1 %d %d\n", q[0][num[0]], q[0][num[0]-1]);
			cnt++;
			num[0]--;
		}
		if(cnt+1 <= n-1)
		{
			printf("2 %d\n", q[0][1]);
			cnt++;
			num[0]--;
		}
	}
	else if(num[2]&1)
	{
		while(cnt+1 <= n-1 && num[2] > 2)
		{
			printf("1 %d %d\n", q[2][num[2]], q[2][num[2]-1]);
			cnt++;
			num[2]--;
		}
		if(cnt+1 <= n-1)
		{
			printf("2 %d\n", q[2][1]);
			cnt++;
			num[2]--;
			if(num[2]) q[2][1] = q[2][2];
		}
	}
	while(cnt+1 <= n-1 && num[2] > 1)
	{
		printf("1 %d %d\n", q[2][num[2]], q[2][num[2]-1]);
		cnt++;
		num[2]--;
	}
	while(cnt+1 <= n-1 && num[0] > 1)
	{
		printf("1 %d %d\n", q[0][num[0]], q[0][num[0]-1]);
		cnt++;
		num[0]--;
	}
	while(cnt+1 <= n-1 && num[1] > 1)
	{
		printf("1 %d %d\n", q[1][num[1]], q[1][num[1]-1]);
		cnt++;
		num[1]--;
	}
	while(cnt+1 <= n-1)
	{
		int tmp = 0;
		putchar('1');
		for(int i = 0; i < 3; ++i)
			if(num[i])
			{
				++tmp;
				printf(" %d", q[i][1]);
				if(tmp == 1) num[i]--;
				else if(tmp == 2) break;
			}
		putchar('\n');
		++cnt;
	}
	return 0;
}
