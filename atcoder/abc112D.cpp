#include <bits/stdc++.h>

using namespace std;

int n, m;

int main()
{
	cin >> n >> m;
	if(m%n == 0)
	{
		cout << m/n << endl;
		return 0;
	}
	for(int i = m/n; i; --i)
	{
		if(m%i) continue;
		cout << i << endl;
		break;
	}
	return 0;
}
