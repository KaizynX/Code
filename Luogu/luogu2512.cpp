#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e6+7;

int n;
long long a[Maxn], ave, s[Maxn], mid, ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        ave += a[i];
    }
    ave /= n;
    for(int i = 1; i <= n; ++i)
        a[i] -= ave;
    for(int i = 1; i <= n; ++i)
        s[i] = s[i-1] + a[i];
    sort(s+1, s+n+1);
    mid = s[(n+1)/2];
    for(int i = 1; i <= n; ++i)
        ans += abs(s[i]- mid);
    cout << ans << endl;
    return 0;
}
