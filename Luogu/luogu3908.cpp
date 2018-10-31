#include <iostream>

using namespace std;

long long n, ans;

int main()
{
	cin >> n;
	for(int i = 0; i < (n+1)%4; ++i)
		ans ^= n-i;
	cout << ans << endl;
	return 0;
}
