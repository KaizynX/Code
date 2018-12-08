#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	cin >> n;
	long long pow2 = 1;
	for(int i = 1; i <= n; ++i)
	{
		pow2 <<= 1;
		if((pow2-1)%7 == 0) cout << i << " " << pow2-1 << endl;
	}
	return 0;
}
