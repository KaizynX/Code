#include <iostream>

using namespace std;

int main()
{
	for(int i = 1; i <= 1e5; ++i)
		if( (i+1)/2 != (i - i/2)) cout << i << endl;
	return 0;
}
