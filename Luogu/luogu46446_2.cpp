#include <bits/stdc++.h>

using namespace std;

const int Maxn = 50;
const int Maxm = (1<<23)+1;

int n, tot;
long long S, a[Maxn], ans;
long long b[2][Maxm];

void solve(int cur, int tail, long long sum, long long *arr)
{
	if(sum == S)
	{
		cout << S << endl;
		exit(0);
	}
    if(cur > tail)
    {
        ans = max(ans, sum);
        return;
    }
    if(sum+a[cur] <= S)
	{
		arr[++arr[0]] = sum+a[cur];
		solve(cur+1, tail, sum+a[cur], arr);
	}
    solve(cur+1, tail, sum, arr);
}

int main()
{
	cin >> S >> n;
    for(int i = 1, v, w; i <= n; ++i)
    {
		cin >> w >> v;
        a[++tot] = w;
        for(int i = 2; i <= v; ++i)
            a[tot] *= w;
        if(a[tot] > S) tot--;
        if(a[tot] == S)
        {
			cout << S << endl;
            return 0;
        }
    }
	solve(1, tot/2, 0, b[0]);
	solve(tot/2+1, tot, 0, b[1]);
	if(!b[0][0] || !b[1][0])
	{
		cout << ans << endl;
		return 0;
	}
	sort(b[0]+1, b[0]+b[0][0]+1);
	sort(b[1]+1, b[1]+b[1][0]+1);
	b[0][0] = unique(b[0]+1, b[0]+b[0][0]+1)-(b[0]+1);
	b[1][0] = unique(b[1]+1, b[1]+b[1][0]+1)-(b[1]+1);
	for(int i = 1; i <= b[0][0]; ++i)
	{
		// b[1][pos] > S-b[0][i]
		// b[1][pos-1] <= S-b[0][i]
		// b[0][i]+b[1][pos-1] <= S
		int pos = upper_bound(b[1]+1, b[1]+b[1][0]+1, S-b[0][i])-b[1];
		if(pos > 1) ans = max(ans, b[0][i]+b[1][pos-1]);
	}
	cout << ans << endl;
    return 0;
}
