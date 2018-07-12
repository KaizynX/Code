#include <iostream>
#include <cstring>

using namespace std;

const int Maxn = 2e3 + 7;

string a, b;
int f[Maxn][Maxn];

int main()
{
	cin >> a >> b;
	int lena = a.length(), lenb = b.length();
	for(int i = 1; i <= lena; ++i) f[i][0] = i;
	for(int j = 1; j <= lenb; ++j) f[0][j] = j;
	for(int i = 1; i <= lena; ++i)
		for(int j = 1; j <= lenb; ++j)
			f[i][j] = min( min(f[i-1][j], f[i][j-1])+1, f[i-1][j-1]+(a[i-1]==b[j-1]?0:1));
	cout << f[lena][lenb] << endl;
	return 0;
}
