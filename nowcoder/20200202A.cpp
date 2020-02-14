#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const int MOD = 1e9+7;

int n;
int a[N];
long long add[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1, l, r; i < n; ++i) {
        l = a[i]; r = a[i+1];
        if (l > r) swap(l, r);
        ++l; --r;
        if (l > r) continue;
        long long w = 1ll*i*(n-i);
        add[l] += w;
        add[r+1] -= w;
    }
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        res += add[i];
        cout << res << endl;
    }
    return 0;
}
