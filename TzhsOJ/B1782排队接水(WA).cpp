#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,a[100000];
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);
	return 0;
}
