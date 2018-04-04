#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	long long n,k;
	cin>>k;
	double a=0;
	for(n=1;;++n)
	{
		a+=1.0/n;
		if(a>k)break;
	}
	cout<<n<<endl;
	return 0;
} 
