#include<iostream>
#include<cstring>
#define b "bilibili"
using namespace std;
int main()
{
	string s;
	cin>>s;
	int fd,ans=0;
	fd=s.find(b,0);
	while(fd!=s.npos)
	{
		ans++;
		fd=s.find(b,fd+8);
	}
	cout<<ans<<endl;
	return 0;
} 
