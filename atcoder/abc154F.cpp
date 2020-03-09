#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e6+7;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

long long A[N], inv[N];

inline long long qpow(long long a, int p)
{
    long long res = 1;
    while (p) {
        if (p&1) res = res*a%MOD;
        a = a*a%MOD;
        p >>= 1;
    }
    return res;
}

inline long long inverse(const long long &a)
{
    return qpow(a, MOD-2);
}

inline void init()
{
    inv[0] = A[0] = 1;
    for (int i = 1; i < N; ++i) {
        A[i] = A[i-1]*i%MOD;
        inv[i] = inverse(A[i]);
    }
}

inline long long C(const int &p, const int &q)
{
    return A[p]*inv[q]%MOD*inv[p-q]%MOD;
}

inline long long calc(const int &x, const int &y)
{
    if (x < 0 || y < 0) return 0;
    long long res = 0;
    for (int i = 0; i <= x; ++i)
        (res += C(i+y+1, i+1)) %= MOD;
    return res;
}

inline void solve()
{
    int r1, r2, c1, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    init();
    long long res = calc(r2, c2)-calc(r2, c1-1)-calc(r1-1, c2)+calc(r1-1, c1-1);
    res = (res%MOD+MOD)%MOD;
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}