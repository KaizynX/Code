#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	freopen("test.in","r",stdin);
	freopen("test_ans.out","w",stdout);

	long long a,b;
	cin >> a >> b;
	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;
	cout << a / b << endl;
	cout << a % b << endl;
	return 0;
}
