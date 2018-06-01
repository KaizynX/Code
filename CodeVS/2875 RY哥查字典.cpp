#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n,m,i;
	string s,S;
	cin>>n;
	for(i=0;i<n;++i)
	{
		cin>>s;
		S=S+s+" ";
	}
	cin>>m;
	for(i=0;i<m;++i)
	{
		cin>>s;
		if(S.find(s)!=s.npos)
			cout<<"Yes"<<endl;
		else 
			cout<<"No"<<endl;
	}
	return 0;
}
