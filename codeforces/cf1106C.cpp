#include <bits/stdc++.h>

using namespace std;

const int Maxn = 3e5+7;

int n;
int a[Maxn];
long long ans;

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a+n);
    for(int i = 0; i < n/2; ++i)
        ans += 1ll*(a[i]+a[n-i-1])*(a[i]+a[n-i-1]);
    cout << ans << endl;
    return 0;
}
