#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int Maxn = 1e5 + 7;

int n;
string key;
string str[Maxn];
vector <string> v;

int main()
{
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> str[i];
	cin  >> key;
	for(int i = 0; i < n; ++i)
	{
		string &tmp = str[i];
		if(tmp.find(key) == 0) v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for(vector<string>::iterator it = v.begin(); it != v.end(); ++it) cout << *it << endl;
	return 0;
}
