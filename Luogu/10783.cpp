#include <iostream>

using namespace std;

long long gcd(long long a,long long b)
{
	if(b)return gcd(b,a%b);
	else if(a==1)return -1;
	else return a;
}

int main()
{
	long long a,b;
	cin>>a>>b;
	if(b>a)swap(a,b);
	cout<<gcd(a,b)<<endl;
	return 0;
} 
