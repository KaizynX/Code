#include <cstdio>
#include <iostream>

using namespace std;

int Q;
long long l, r;

int main()
{
	cin >> Q;
	while(Q--)
	{
		cin >> l >> r;
		long long a = l+r, b = r-l+1;
		if(a%2 == 0) a /= 2;
		else b /= 2;
		a %= 9;
		b %= 9;
		cout << a*b%9 << endl;
	}
	return 0;
}
