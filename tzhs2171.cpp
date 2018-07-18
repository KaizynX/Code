#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct Time
{
	int h[6], m[6], s[6];
	Time(){}
	Time(string &str){ *this = str; }
	Time operator = (const string &str)
	{
		memset(h, 0, sizeof h);
		memset(m, 0, sizeof m);
		memset(s, 0, sizeof s);
		int H = (str[0]-'0')*10+str[1]-'0',
			M = (str[3]-'0')*10+str[4]-'0',
			S = (str[6]-'0')*10+str[7]-'0';
		int pos = 0;
		while(H)
		{
			h[pos++] = H & 1;
			H >>= 1;
		}
		pos = 0;
		while(M)
		{
			m[pos++] = M & 1;
			M >>= 1;
		}
		pos = 0;
		while(S)
		{
			s[pos++] = S & 1;
			S >>= 1;
		}
		return *this;
	}
} t;

int main()
{
	string str;
	while(cin >> str)
	{
		t = str;
		for(int i = 5; i >= 0; --i)
			cout << t.h[i] << t.m[i] << t.s[i];
		cout << " ";
		for(int i = 5; i >= 0; --i) cout << t.h[i];
		for(int i = 5; i >= 0; --i) cout << t.m[i];
		for(int i = 5; i >= 0; --i) cout << t.s[i];
		cout << endl;
	}
	return 0;
}
