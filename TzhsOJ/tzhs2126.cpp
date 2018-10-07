#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int Maxn = 1e3 + 7;

string a, b;

int main()
{
	while(cin >> a && a != "#")
	{
		cin >> b;
		int cnt = 0;
		size_t pos = 0, len = b.length();
		while((pos = a.find(b, pos)) != a.npos)
		{
			++cnt;
			pos += len;
		}
		cout << cnt << endl;
	}
	return 0;
}
