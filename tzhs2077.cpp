#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int Maxn = 1e3 + 7;

int n;
string s[Maxn];

bool cmp(string a, string b)
{
	return a+b > b+a;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> s[i];
	sort(s, s+n, cmp);
	for(int i = 0; i < n; ++i) cout << s[i];
	return 0;
}
