#include <iostream>

using namespace std;

long long n, ans;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; ++i)
		ans ^= i;
	cout << ans << endl;
	return 0;
}
