#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int Maxn = 5e4 + 7;

int n;
int a[Maxn];
priority_queue<int> q_less;
priority_queue<int, vector<int>, greater<int> > q_greater;

int main()
{
	scanf("%d", &n);
	for(int i = 0, a; i < n; ++i)
	{
		scanf("%d", &a);
		q_less.push(a);
		q_greater.push(a);
	}
	int a, b;
	while(q_less.size() > 1)
	{
		a = q_less.top(); q_less.pop();
		b = q_less.top(); q_less.pop();
		q_less.push(a*b+1);
	}
	while(q_greater.size() > 1)
	{
		a = q_greater.top(); q_greater.pop();
		b = q_greater.top(); q_greater.pop();
		q_greater.push(a*b+1);
	}
	printf("%d", q_greater.top() - q_less.top());
	return 0;
}
