#include <iostream>

using namespace std;

int T, n, judge;

int main()
{
	cin >> T;
	while(T--)
	{
		judge = 0;
		cin >> n;
		for(int i = 0, tmp; i < n; ++i)
		{
			cin >> tmp;
			judge ^= tmp;
		}
		cout << (judge == 0 ? "No" : "Yes") << endl;
	}
	return 0;
}
