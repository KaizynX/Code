#include <iostream>
using namespace std;
const int maxn=105;
int n,m25,m50,m100;
int main()
{
	int i,m;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>m;
		if(m==25)m25++;
		else if(m==50)m50++;
		else if(m==100)m100++;
	}
	if(m50>m25)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	m25-=m50;
	while(m100)
	{
		if(m50)
		{
			m50--;
			if(m25)
				m25--;
			else
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
		else if(m25<3)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		else
			m25-=3;
		m100--;
	}
	cout<<"YES"<<endl;
	return 0;
}
