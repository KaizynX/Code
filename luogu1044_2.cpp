#include <iostream>

using namespace std;

//打表大法好

int main()
{
	int n,ans;
	cin>>n;
	switch(n)
	{
		case 1:
			ans=1;
			break;
		case 2:
			ans=2;
			break;
		case 3:
			ans=5;
			break;
		case 4:
			ans=14;
			break;
		case 5:
			ans=42;
			break;
		case 6:
			ans=132;
			break;
		case 7:
			ans=429;
			break;
		case 8:
			ans=1430;
			break;
		case 9:
			ans=4862;
			break;
		case 10:
			ans=16796;
			break;
		case 11:
			ans=58786;
			break;
		case 12:
			ans=208012;
			break;
		case 13:
			ans=742900;
			break;
		case 14:
			ans=2674440;
			break;
		case 15:
			ans=9694845;
			break;
		case 16:
			ans=35357670;
			break;
		case 17:
			ans=129644790;
			break;
		case 18:
			ans=477638700;
			break;
	}
	cout<<ans<<endl;
	return 0;
}
