#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct node
{
	int id,b;
	bool operator < (const node &c)const
	{
		if(b == c.b)return id < c.id;
		return b < c.b;
	}
}tmp;

priority_queue <node> q[5];

int main()
{
	int n,a,b,id;
	string ope;
	while(cin>>n)
	{
		id = 0;
		for(int i = 0; i < n; ++ i)
		{
			cin >> ope;
			if(ope[0] == 'I')
			{
				cin >> a >> b;
				tmp.b = b;
				tmp.id = ++id;
				q[a].push(tmp);
			}
			else
			{
				cin >> a;
				if(q[a].empty())
					cout << "EMPTY" << endl;
				else
				{
					cout << q[a].top().id << endl;
					q[a].pop();
				}
			}
		}
	}
	return 0;
}
