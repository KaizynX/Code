#include <cstdio>
#include <iostream>
#include <ctime>
#include <random>

using namespace std;

const long long Mo = 3037000000;
// ∑¿÷π ^2 ±¨ long long
int main()
{
	freopen("test.in","w",stdout);
	long long a,b;
	default_random_engine rd(static_cast<unsigned>(time(NULL)));
	a = ( rd() - rd() ) % Mo;
	b = ( rd() - rd() ) % Mo;
	cout << a << " " << b << endl;
	return 0;
}
