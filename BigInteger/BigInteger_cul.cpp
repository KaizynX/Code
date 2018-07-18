#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	freopen("D:\\test.in","r",stdin);
	freopen("D:\\test_ans.out","w",stdout);

	long long a,b;
	cin >> a >> b;
	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;
	cout << a / b << endl;
	cout << a % b << endl;
	return 0;
}
