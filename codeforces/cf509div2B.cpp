#include <cstdio>
#include <iostream>

using namespace std;

long long a, b, x, y;

long long gcd(long long a, long long b)
{
	return !b ? a : gcd(b, a%b);
}

int main()
{
	cin >> a >> b >> x >> y;
	long long tmp = gcd(x, y);
	x /= tmp; y /= tmp;
	cout << min(a/x, b/y) << endl;
	return 0;
}
