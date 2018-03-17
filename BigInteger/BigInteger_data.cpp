#include <cstdio>
#include <iostream>
#include <ctime>
#include <random>
#include <fstream>

using namespace std;

const long long Mo = 3037000000;
// ∑¿÷π ^2 ±¨ long long
int main()
{
	//freopen("test.in","w",stdout);
	ofstream of("E:\\test.in",ios::out);
	long long a,b;
	default_random_engine rd(static_cast<unsigned>(time(NULL)));
	a = ( rd() - rd() ) % Mo;
	b = ( rd() - rd() ) % Mo;
	of << a << " " << b << endl;
	of.close();
	//system("del E:\\test.in");
	return 0;
}
