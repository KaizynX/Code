#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e4 + 7;

int n, k;
int a[Maxn];

int main()
{
	cin >> n >> k;
	for(register int i = 0; i < n; ++ i)
		cin >> a[i];
	sort(a,a + n);
	n = unique(a,a + n) - a;
	if(k > n) cout << "NO RESULT" << endl;
	else cout << a[k-1] << endl;
	return 0;
}
