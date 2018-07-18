#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100005;
int f[maxn],n;
string s;
int main()
{
	int a,i,sum=0,len;
	cin>>s;
	len=s.length();
	for(i=0;i<len;++i)
	{
		if(s[i]=='1')
			sum++;
		f[i]=sum;
	}
	for(i=0;i<len;++i)
	{
		if(f[i]==(len-i-1)-(f[len-1]-f[i]))
		{
			cout<<i+1<<endl;
			return 0;
		}
	}
	cout<<len+1<<endl;
	return 0;
}

