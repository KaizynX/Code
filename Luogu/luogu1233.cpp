#include <iostream>
#include <algorithm>
#include <cstring>

#define DEBUG

using namespace std;

const int Maxn = 5000 + 7;

int n, ans, cnt;
bool vis[Maxn];

struct stick
{
	int l,w;
	bool operator < (const stick &b) const
	{
		if(l == b.l) return w > b.w;
		return l > b.l;
	}
}a[Maxn];

int main()
{
	int cur;
	memset(vis,0,sizeof vis);
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i].l >> a[i].w;
	}
	sort(a,a + n);
#ifdef DEBUG
	for(int i = 0; i < n ; ++i)
		cout << a[i].l << ' ' << a[i].w << endl;
	cout << endl;
#endif

	while(cnt < n)
	{
		cur = 0;
		while(vis[cur]) ++cur;
		vis[cur] = true;
		++cnt;
		for(int i = cur + 1; i < n; ++i)
		{
			if(vis[i]) continue;
			if(a[cur].l >= a[i].l && a[cur].w >= a[i].w)
			{
				cur = i;
				++cnt;
				vis[cur] = true;
			}
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
}
