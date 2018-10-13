#include <bits/stdc++.h>

using namespace std;

const int Maxn = 107;

int n, m, root, son;
int r[Maxn];
vector<int> e[Maxn];

int main()
{
	cin >> n >> m;
	for(int i = 1, x, y; i <= m; ++i)
	{
		cin >> x >> y;
		r[y]++;
		e[x].push_back(y);
	}
	for(int i = 1; i <= n; ++i)
	{
		if(!r[i]) root = i;
		if(e[i].size() > e[son].size()) son = i;
	}
	cout << root << endl << son << endl;
	sort(e[son].begin(), e[son].end());
	for(int i = 0; i < e[son].size(); ++i)
		cout << e[son][i] << " ";
	return 0;
}
