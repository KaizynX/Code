#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int Maxn = 1e5 + 7;

int n;
long long s[Maxn][3];
// 0 - COW   1 - OW  2 - W
string str;

int main()
{
	cin >> n >> str;
	for(int i = n-1; i >= 0; --i)
	{
		for(int j = 0; j < 3; ++j) s[i][j] = s[i+1][j];
		if(str[i] == 'W')
		{
			s[i][2] += 1;
		}
		else if(str[i] == 'O')
		{
			s[i][1] += s[i+1][2];
		}
		else if(str[i] == 'C')
		{
			s[i][0] += s[i+1][1];
		}
		/// printf("i:%d %d %d %d\n", i, s[i][0], s[i][1], s[i][2]); ////////
	}
	printf("%lld\n", s[0][0]);
	return 0;
}
