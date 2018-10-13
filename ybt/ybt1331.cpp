#include <bits/stdc++.h>

using namespace std;

stack<long long> s;

int main()
{
	char c;
	while((c=getchar()) != '@')
	{
		long long a, b;
		if(isdigit(c))
		{
			a = c-'0';
			while(isdigit(c=getchar()))
				a = a*10+c-'0';
			s.push(a);
		}
		else if(c == '+')
		{
			b = s.top(); s.pop();
			a = s.top(); s.pop();
			s.push(a+b);
		}
		else if(c == '-')
		{
			b = s.top(); s.pop();
			a = s.top(); s.pop();
			s.push(a-b);
		}
		else if(c == '*')
		{
			b = s.top(); s.pop();
			a = s.top(); s.pop();
			s.push(a*b);
		}
		else if(c == '/')
		{
			b = s.top(); s.pop();
			a = s.top(); s.pop();
			s.push(a/b);
		}
	}
	printf("%lld\n", s.top());
	return 0;
}
