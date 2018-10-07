#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 5e3+7;

int n, a[Maxn], s[Maxn];

inline int check(int k)
{
	memset(s, 0, sizeof s);
	int cur = 0, cnt = 0, now;
	for(int i = 1; i <= n; ++i)
	{
		// cur >= 0
		cur += s[i];
		now = (a[i]+cur)&1;
		if(!now)
		{
			if(i <= n-k+1)
			{
				cnt++;
				// s[cur]++;
				cur++;
				s[i+k] = -1;
			}
			else return -1;
		}
	}
	return cnt;
}

int main()
{
	char c;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		c = ' ';
		while(c != 'B' && c != 'F') c = getchar();
		// a[i] = c == 'B' ? 1 : 0;
		if(c == 'F') a[i] = 1;
	}
	for(int k = n; k; --k)
	{
		int m = check(k);
		if(m == -1) continue;
		printf("%d %d\n", k, m);
		break;
	}
	return 0;
}
