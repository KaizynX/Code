#include <iostream>
#include <cstdio> 
using namespace std;
long long an,orr,sum;
int main()
{
	while(cin>>an>>orr>>sum)
		cout<<an<<" "<<sum-an-orr<<" "<<orr<<endl;
	return 0;
}
