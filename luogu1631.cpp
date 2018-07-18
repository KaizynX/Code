#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

const int Maxn = 1e+5 + 7;

int n;
int a[Maxn], b[Maxn];
map< pair<int,int>, bool > m;

struct node
{
	int ia,ib,v;
	
	node (int ia = 0, int ib = 0) : ia(ia), ib(ib) { cal(); }

	void cal() { v = a[ia] + b[ib]; }

	bool operator < (const node &nex) const
	{
		return v > nex.v;
	}
} tmp;

priority_queue <node> q;

inline void operate(int ia,int ib)
{
	if(m.find( make_pair(ia,ib ) ) == m.end()) // hasn't been visited
	{
		m.insert( make_pair( make_pair(ia,ib), true ) );
		q.push(node(ia,ib));
	}
}

int main()
{
	int cnt = 0;
	scanf("%d",&n);
	for(int i = 0; i < n; ++ i)
		scanf("%d",a + i);
	for(int i = 0; i < n; ++ i)
		scanf("%d",b + i);

	sort(a,a+n);
	sort(b,b+n);

	operate(0,0);
	
	while(++cnt <= n)
	{
		tmp = q.top();
		q.pop();
		printf("%d ",tmp.v);
		operate(tmp.ia,tmp.ib+1);
		operate(tmp.ia+1,tmp.ib);
	}

	return 0;
}
