#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n, k, ans;
int h[Maxn];

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> h[i];
    sort(h+1, h+n+1);
    ans = h[k]-h[1];
    for(int i = 2; i+k-1 <= n; ++i)
        ans = min(ans, h[i+k-1]-h[i]);
    cout << ans << endl;
    return 0;
}
