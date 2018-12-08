#include <bits/stdc++.h>

using namespace std;

string str;

int main()
{
	while(cin >> str)
	{
		int flag = 1;
		for(int i = 0; i < str.length(); ++i)
		{
			if(str[i] == '-') continue;
			if(str[i] != '1')
			{
				flag = 0;
				break;
			}
		}
		cout << (flag ? "Accepted" : "Wrong Answer") << endl;
	}
	return 0;
}
