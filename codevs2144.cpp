#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 40;

int n, m, ans = Maxn, a[Maxn];

void dfs(int cur, int now, int choose)
{
    if(now == m) ans = min(ans, choose);
    if(now > m) return;
    if(cur >= n) return;
    if(choose >= ans) return;
    dfs(cur+1, now+a[cur], choose+1);
    dfs(cur+1, now, choose);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a+n); reverse(a, a+n);
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}
