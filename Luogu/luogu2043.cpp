#include <iostream>

using namespace std;

const int Maxn = 1e4+7;

int n;

int main()
{
	cin >> n;
	for(int i = 2, cnt; n > 1; i += 2)
	{
		if(n%i == 0)
		{
			cnt = 0;
			while(n%i == 0)
			{
				n /= i;
				cnt++;
			}
			cout << i << " " << cnt << endl;
		}
		if(i == 2) i--;
	}
	return 0;
}
