#include <iostream>

using namespace std;

const int INF = 0x7f7f7f7f;

int f3[20], f4[20];

int main()
{
	f3[1] = 1; f4[1] = 1;
	for(int i = 2; i <= 12; ++i) f3[i] = f3[i-1] * 2 + 1;
	for(int i = 2; i <= 12; ++i)
	{
		f4[i] = INF;
		for(int j = 1; j <= i; ++j)
		{
			f4[i] = min(f4[i],2*f4[j] + f3[i-j]);
		}
	}
	for(int i = 1; i <= 12; ++i)
		cout << f4[i] << endl;
	return 0;
}
