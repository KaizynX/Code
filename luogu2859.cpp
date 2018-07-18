#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int Maxn = 5e4 + 7;

int n;
int f[Maxn];

struct Cow
{
	int bg, ed, num;
	bool operator < (const Cow &b) const
	{
		return bg < b.bg;
	}
} a[Maxn];

struct Node
{
	int num, t;
	Node() {}
	Node(int num,int t) :num(num),t(t) {}
	bool operator < (const Node &b) const 
	{
		return t > b.t;
	}
} tmp;

priority_queue <Node> q;

inline int getint();

int main()
{
	n = getint();
	q.push(Node(1,0));
	for(int i = 1; i <= n; ++i) { a[i].bg = getint(); a[i].ed = getint(); a[i].num = i; }
	sort(a+1,a+n+1);
	for(int i = 1, cur; i <= n; ++i)
	{
		cur = a[i].num;
		if(a[i].bg <= q.top().t)
		{
			f[cur] = q.size() + 1;
			q.push(Node(f[cur],a[i].ed));
		}
		else
		{
			tmp = q.top();
			q.pop();
			tmp.t = a[i].ed;
			f[cur] = tmp.num;
			q.push(tmp);
		}
	}
	printf("%d\n",q.size());
	for(int i = 1; i <= n; ++i) printf("%d\n",f[i]);
	return 0;
}

inline int getint()
{
	char c;
	while((c=getchar()) < '0' || c > '9');
	int res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = res * 10 + c - '0';
	return res;
}
