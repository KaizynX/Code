#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdio>
// Linsanity is back 	
// Who¡¯s Kobe? 
// Fisherman can¡¯t stop us
// Average ABCDE on a good day
using namespace std;

int n;
const int MAXN = 200005;
long long a[MAXN];
vector<int> curr, z;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;

	long long neg = 0, idxn = 0, smallneg = 1e9 + 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] < 0)
		{
			neg++;
			if(abs(a[i]) < smallneg)
			{
				smallneg = abs(a[i]);
				idxn = i;
			}
		}
		if(a[i] == 0)
			z.push_back(i);
	}

	int counter = 0;
	for(int i = 0; i < (int)z.size() - 1; i++)
	{
		cout << 1 << " " << z[i] << " " << z[i + 1] << "\n";
		counter++;
	}

	int pos = -1;
	if (!z.empty())
		pos = z.back();
	if(neg % 2 == 1)
	{
		pos = idxn;
		if(!z.empty())
		{
			cout << 1 << " " << z.back() << " " << idxn << "\n";
			counter++;
		}
	}
	if(counter == n - 1)
		return 0;
	else if (pos != -1)
		cout << 2 << " " << pos << "\n";

	for(int i = 1; i <= n; i++)
		if(a[i] != 0 && (neg % 2 == 0 || i != idxn))
			curr.push_back(i);

	for(int i = 0; i < curr.size() - 1; i++)
		cout << 1 << " " << curr[i] << " " << curr[i + 1] << "\n";

	return 0;
}
