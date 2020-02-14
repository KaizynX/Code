#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const int MOD = 998244353;

int n;
int a[N];

inline long long qpow(long long b, long long p)
{
    long long res = 1;
    while (p) {
        if (p&1) res = res*b%MOD;
        b = b*b%MOD;
        p >>= 1;
    }
    return res;
}

int main()
{
    cin >> n;
    long long sum = 0, res = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        (sum += qpow(2, a[i])) %= MOD;
    }
    for (int i = 1; i <= n; ++i) {
        (res += qpow(2, a[i])*sum%MOD) %= MOD;
    }
    cout << res << endl;
    return 0;
}
