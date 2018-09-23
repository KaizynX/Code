#include <stack>
#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 2e5+7;
const int INF = 1e9+7;

int n, nega = -INF, negid, cnt, negn;
stack<int> s, zero;

int main()
{
	scanf("%d", &n);
	for(int i = 1, a; i <= n; ++i)
	{
		scanf("%d", &a);
		if(a == 0) zero.push(i);
		else
		{
			if(a < 0) negn++;
			if(a < 0 && a > nega)
			{
				nega = a;
				negid = i;
			}
			s.push(i);
		}
	}
	int tmp;
	while(zero.size() > 1)
	{
		tmp = zero.top(); zero.pop();
		printf("1 %d %d\n", tmp, zero.top());
		cnt++;
	}
	if(negn&1)
	{
		if(zero.size())
		{
			printf("1 %d %d\n", zero.top(), negid);
			cnt++;
			zero.pop();
		}
		if(cnt < n-1)
		{
			printf("2 %d\n", negid);
			cnt++;
		}
	}
	if(cnt < n-1 && zero.size())
	{
		printf("2 %d\n", zero.top());
		cnt++;
	}
	if(cnt >= n-1) return 0;
	while(s.size() > 1 && cnt < n-1)
	{
		tmp = s.top(); s.pop();
		if(negn&1 && tmp == negid)
		{
			tmp = s.top(); s.pop();
		}
		if(negn&1 && s.top() == negid)
		{
			s.pop();
		}
		printf("1 %d %d\n", tmp, s.top());
		cnt++;
	}
	return 0;
}
