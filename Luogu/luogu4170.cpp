#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
// #define DEBUG

using namespace std;

const int Maxn = 60;

int len;
string str, end_str;
map<string, int> vis;
queue<pair<string, int> > q;

int main()
{
	cin >> str;
	str = "0"+str+"0";
	len = str.length();
	end_str = string(len, '0');
	q.push(make_pair(str, 0));
	vis.insert(make_pair(str, 1));
	pair<string, int> cur;
	int i, j;
	string tmp, cur_str;
	while(q.size())
	{
		cur = q.front();
		q.pop();
		i = 1;
#ifdef DEBUG
		cout << "cur: " << cur.first << " " << cur.second << endl;
#endif
		while(i < len-1)
		{
			while(i < len && cur.first[i] == '0') i++;
			// find a piece contain same char [i, j)
			j = i+1;
			while(j < len && cur.first[i] == cur.first[j]) j++;
			// paint it as [i-1]
			cur_str = cur.first;
			tmp = cur_str.replace(i, j-i, string(j-i, cur.first[i-1]));
#ifdef DEBUG
			cout << tmp << endl;
#endif
			if(tmp == end_str)
			{
				printf("%d\n", cur.second+1);
				return 0;
			}
			if(!vis.count(tmp))
			{
				q.push(make_pair(tmp, cur.second+1));
				vis.insert(make_pair(tmp, 1));
			}
			// paint it as [j]
			cur_str = cur.first;
			tmp = cur_str.replace(i, j-i, string(j-i, cur.first[j]));
#ifdef DEBUG
			cout << tmp << endl;
#endif
			if(tmp == end_str)
			{
				printf("%d\n", cur.second+1);
				return 0;
			}
			if(!vis.count(tmp))
			{
				q.push(make_pair(tmp, cur.second+1));
				vis.insert(make_pair(tmp, 1));
			}
			i = j;
		}
	}
	return 0;
}
