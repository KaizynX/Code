#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	freopen("E:\\test.in","r",stdin);
	freopen("E:\\test_ans.out","w",stdout);

	long long a,b;
	cin >> a >> b;
	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;
	cout << a / b << endl;
	cout << a % b << endl;
	return 0;
}
