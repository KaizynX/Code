#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int MOD = 1e9+7;

long long x, n, res = 1;

inline long long qpow(long long a, long long p)
{
    long long res = 1;
    while (p) {
        // if (p&1) res = static_cast<int>(1ll*res*a%MOD);
        // a = static_cast<int>(1ll*a*a%MOD);
        if (p&1) res = res*a%MOD;
        a = a*a%MOD;
        p >>= 1;
    }
    return res;
}

int main()
{
    cin >> x >> n;
    for (long long i = 2; i*i <= x; ++i) {
        if (x%i == 0) {
            while(x%i == 0) x /= i;
            long long cnt = 0;
            for (long long j = i; j <= n;) {
                cnt += n/j;
                if (n/j < i) break;
                j *= i;
            }
            res = res*qpow(i, cnt)%MOD;
#ifdef DEBUG
            cout << i << " " << cnt << endl;
#endif
            /*
            int cnt = 0;
            while (n%i == 0) n /= i, ++cnt;
            res = res*qpow(i, cnt)%MOD;
            // cout << i << " " << cnt << endl;
            */
        }
    }
    if (x > 1) {
        long long i = x;
        long long cnt = 0;
        for (long long j = i; j <= n;) {
#ifdef DEBUG
            cout << j << endl;
#endif
            cnt += n/j;
            if (n/j < i) break;
            j *= i;
        }
            // res = res*qpow(i, n/j)%MOD;
        res = res*qpow(i, cnt)%MOD;
#ifdef DEBUG
        cout << i << " " << cnt << endl;
#endif
    }
    cout << res << endl;
    return 0;
}
