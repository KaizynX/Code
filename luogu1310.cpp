#include <stack>
#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e5+7;
const int Mo = 1e4+7;

int n;
char str[Maxn];
stack<int> s;

struct Node
{
	int tail, num0, num1;
	Node(int t = -1, int n0 = 1, int n1 = 1) : tail(t), num0(n0), num1(n1) {}
} a[Maxn];

inline void solve(int head, int tail)
{
	int hasp = 0;
	a[head].tail = tail;
	for(int i = head+1; i < tail; ++i)
	{
		if(str[i] == '*')
		{
			int j = i;
			while(j < tail && (str[j] == '*' || str[j] == '('))
			{
				if(str[j] == '(')
				{
					a[i].num0 = (a[i].num0*(a[j].num0+a[j].num1)+a[i].num1*a[j].num0)%Mo;
					a[i].num1 = a[i].num1*a[j].num1%Mo;
					j = a[i].tail;
				}
				else 
				{
					a[i].num0 = (a[i].num0*2+a[i].num1)%Mo;
					// a[i].num1 = a[i].num1;
				}
				j++;
			}
			j--;
			a[i].tail = j;
			i = j;
		}
		else if(str[i] == '+') hasp = 1;
	}
	if(!hasp)
	{
		a[head].num0 = a[head+1].num0;
		a[head].num1 = a[head+1].num1;
		return;
	}
	for(int i = head+1; i < tail; ++i)
	{
		if(str[i] == '+')
		{
			// a[head].num0 = a[head].num0;
			a[head].num1 = (a[head].num0+a[head].num1*2)%Mo;
		}
		else if(a[i].tail != -1)
		{
			a[head].num1 = (a[head].num0*a[i].num1+a[head].num1*(a[i].num0+a[i].num1))%Mo;
			a[head].num0 = a[head].num0*a[i].num0%Mo;
		}
	}
}

int main()
{
	scanf("%d", &n);
	scanf("%s", str+1);
	for(int i = 1; i <= n; ++i)
	{
		if(str[i] == '(') s.push(i);
		else if(str[i] == ')')
		{
			int tmp = s.top();
			s.pop();
			solve(tmp, i);
		}
	}
	int head = 1, tail = n;
	while(str[head] == '(') head++;
	while(str[tail] == ')') tail--;
	solve(head-1, tail+1);
	printf("%d\n", a[head-1].num0%Mo);
	return 0;
}
