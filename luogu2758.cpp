#include <iostream>
#include <cmath>
#include <cstring>
#define DEBUG

using namespace std;

const int Maxn = 2e3 + 7;

string a, b;
int f[Maxn][Maxn];

int main()
{
	cin >> a >> b;
	int len_a = a.length(), len_b = b.length();
	for(int i = 0; i < len_a; ++i)
		for(int j = 0; j < len_b; ++j)
		{
			f[i+1][j+1] = max(f[i][j+1], f[i+1][j]);
			if(a[i] == b[j]) f[i+1][j+1] = max(f[i+1][j+1], f[i][j] + 1);
#ifdef DEBUG
			cout << i << " " << j << " " << f[i][j] << endl;
#endif
		}
#ifdef DEBUG
	cout << f[len_a][len_b] << endl;
#endif
	cout << abs(len_a - len_b) + len_b - f[len_a][len_b] << endl;
	return 0;
}
