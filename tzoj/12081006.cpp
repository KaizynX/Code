#include <bits/stdc++.h>

using namespace std;

const string today = "12-08";

string str;

int main()
{
	while(cin >> str)
	{
		if(str == today)
		{
			cout << 0 << endl;
			continue;
		}
		if(str < today)
		{
			cout << "+";
			int dd = (str[3]-'0')*10+(str[4]-'0');
			if(dd < 8) cout << 8-dd << endl;
			else cout << 8+30-dd << endl;
		}
		else if(str > today)
		{
			cout << "-";
			int dd = (str[3]-'0')*10+(str[4]-'0');
			cout << dd-8 << endl;
		}
	}
	return 0;
}
