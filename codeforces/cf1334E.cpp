/*
 * @Author: Kaizyn
 * @Date: 2020-04-11 19:13:12
 * @LastEditTime: 2020-04-11 20:48:39
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int q;
long long D, x, y;
long long fac[N], inv[N];
vector<long long> prime;

inline void get_fac() {
    long long x = D;
    for (long long i = 2; i*i <= x; ++i) {
        if (x%i) continue;
        prime.emplace_back(i);
        while (x%i == 0) x /= i;
    }
    if (x > 1) prime.emplace_back(x);
}

inline long long calc(long long x) {
    long long res = 1;
    int sum = 0;
    for (long long &p : prime) {
        if (x%p) continue;
        int k = 0;
        while (x%p == 0) x /= p, ++k;
        sum += k;
        (res *= inv[k]) %= MOD;
    }
    (res *= fac[sum]) %= MOD;
    return res;
}

inline void solve() {
    cin >> D >> q;
    get_fac();
    while (q--) {
        cin >> x >> y;
        long long g = __gcd(x, y);
        x /= g; y /= g;
        cout << calc(x)*calc(y)%MOD << endl;
    }
}

inline void init() {
    static const int SZ = 100;
    inv[0] = inv[1] = fac[0] = fac[1] = 1;
    for(int i = 2; i <= SZ; ++i) {
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = (MOD-MOD/i)*inv[MOD%i]%MOD;
    }
    for (int i = 2; i <= SZ; ++i) {
        (inv[i] *= inv[i-1]) %= MOD;
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    init();
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}