#include <iostream>
#include <cstring>

using namespace std;

const int Maxn = 2e3 + 7;

string a, b;
int f[Maxn][Maxn];

int dp(int i, int j)
{
	if(f[i][j] != -1) return f[i][j];
	if(i == 0) return f[i][j] = j;
	if(j == 0) return f[i][j] = i;
	return f[i][j] = min( min(dp(i, j-1)+1, dp(i-1, j)+1), dp(i-1, j-1) + (a[i-1] == b[j-1] ? 0 : 1));
}

int main()
{
	cin >> a >> b;
	memset(f, -1, sizeof f);
	cout << dp(a.length(), b.length()) << endl;
	return 0;
}
