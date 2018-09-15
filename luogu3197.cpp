#include <cstdio>
#include <iostream>

using namespace std;

const int Mo = 1e5+3;

long long m, n;

// m^n-m*(m-1)^(n-1)

inline long long quick_m(long long a, long long p)
{
	long long res = 1;
	a %= Mo;
	while(p)
	{
		if(p&1) res = res*a%Mo;
		p >>= 1;
		a = a*a%Mo;
	}
	return res;
}

int main()
{
	cin >> m >> n;
	cout << ((quick_m(m, n)-m*quick_m(m-1, n-1)%Mo)%Mo+Mo)%Mo << endl;
	return 0;
}
