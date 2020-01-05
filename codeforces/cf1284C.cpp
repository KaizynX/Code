#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+7;

int n, m;
long long res;
long long f[N];

int main()
{
    cin >> n >> m;
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
        f[i] = (f[i-1]*i)%m;
    for (int i = 1; i <= n; ++i) {
        (res += (n-i+1ll)*(n-i+1ll)%m*f[i]%m*f[n-i]%m) %= m;
    }
    cout << res << endl;
    return 0;
}
