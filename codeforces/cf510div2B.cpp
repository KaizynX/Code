#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int INF = 1e8+7;

int n, c[8];
string str;

// a 1 b 2 c 4
// ab 3 ac 5 bc 6 abc 7

int main()
{
	for(int i = 1; i <= 7; ++i) c[i] = INF;
	cin >> n;
	for(int i = 1, tmp, k; i <= n; ++i)
	{
		cin >> tmp >> str;
		k = 0;
		for(int i = 0; i < str.length(); ++i)
			k += 1<<(str[i]-'A');
		c[k] = min(c[k], tmp);
	}
	int res = c[7];
	res = min(res, c[1]+c[2]+c[4]);
	res = min(res, c[3]+c[4]);
	res = min(res, c[5]+c[2]);
	res = min(res, c[6]+c[1]);
	res = min(res, c[3]+c[5]);
	res = min(res, c[3]+c[6]);
	res = min(res, c[5]+c[6]);
	printf("%d\n", res == INF ? -1 : res);
	return 0;
}
