#include <iostream>

using namespace std;

int n, sum;

int main()
{
	cin >> n;
	for(int i = 0, tmp; i < n; ++i)
	{
		cin >> tmp;
		sum = (sum + tmp) & 1;
	}
	cout << (sum == 0 ? "Bob" : "Alice") << endl;
	return 0;
}
