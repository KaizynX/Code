#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn = 2e3 + 7;

int n, ans;
int tian[Maxn], king[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", tian+i);
	for(int i = 0; i < n; ++i) scanf("%d", king+i);
	sort(tian, tian+n); reverse(tian, tian+n);
	sort(king, king+n); reverse(king, king+n);
	for(int head_t = 0, tail_t = n, head_k = 0, tail_k = n; head_t < tail_t; )
	{
		if(tian[head_t] > king[head_k]) { ans += 200; ++head_t; ++head_k; }
		else if(tian[head_t] < king[head_k]) { ans -= 200; --tail_t; ++head_k; }
		else // tian[head_t] == king[head_k]
		{
			if(tian[tail_t-1] > king[tail_k-1]) { ans += 200; --tail_t; --tail_k; }
			else 
			{
				if(tian[tail_t-1] < king[head_k]) ans -= 200;
				--tail_t; ++head_k;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
