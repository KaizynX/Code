#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

string k,c,m;

void ToLower(string &s)//转化为小写
{
	for(int i=0;i<s.length();++i)
	{
		if(s[i]<'a')
		{
			s[i]+=32;
		}
	}
}

int main()
{
	int now,lenk;
	cin>>k>>c;
	ToLower(k);
	lenk=k.length();
	for(int i=0;i<c.length();++i)
	{
		now=k[i%lenk]-'a';
		if(c[i]>='A' && c[i]<='Z')
		{
			c[i]-=now;
			if(c[i]<'A')
				c[i]+=26;
		}
		else 
		{
			c[i]-=now;
			if(c[i]<'a')
				c[i]+=26;
		}
	}
	cout<<c;
	return 0;
}
