#include <bits/stdc++.h>

using namespace std;

const int Maxn = 207;

int n, ans;
int a[Maxn], f[Maxn], nex[Maxn];

int main()
{
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	ans = n;
	for(int i = n; i; --i)
	{
		f[i] = 1;
		for(int j = i+1; j <= n; ++j)
		{
			if(a[i] < a[j] && f[i] < f[j]+1)
			{
				f[i] = f[j]+1;
				nex[i] = j;
			}
		}
		if(f[i] > f[ans]) ans = i;
	}
	cout << "max=" << f[ans] << endl << a[ans] << " ";
	for(int cur = nex[ans]; cur; cur = nex[cur])
		cout << a[cur] << " ";
	return 0;
}
