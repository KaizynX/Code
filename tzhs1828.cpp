#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

const int Maxk = 15;

queue <string> q;
map <string , bool> m;
string n;
int k,ans;
string c1[Maxk], c2[Maxk];
// change from c1 to c2

int main()
{
	cin >> n >> k;
	for(int i = 0; i < k; ++ i)
	{
		cin >> c1[i] >> c2[i];
	}
	// no change
	ans ++;
	m.insert(make_pair(n,true));
	q.push(n);

	string tmp,nex;
	size_t cur,pos;
	while(!q.empty())
	{
		cur = 0;
		tmp = q.front();
		q.pop();
		for(int i = 0; i < k; ++ i)
		{
			pos = tmp.find(c1[i],cur);
			while( pos != string::npos)
			{
				nex = tmp.replace(pos,c1[i].length(),c2[i]);
				if(m.find(nex) != m.end())
				{
					q.push(nex);
					ans ++;
				}
				cur ++;
				pos = tmp.find(c1[i],cur);
			}
		}
	}

	cout << ans << endl;
	return 0;
}
