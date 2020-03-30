/*
 * @Author: Kaizyn
 * @Date: 2020-03-28 10:29:11
 * @LastEditTime: 2020-03-28 11:18:06
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD)
{
    long long res = 1, x = a;
    for (H i = p; i; i >>= 1, x = x*x%mo)
        if (i&1) res = res*x%mo;
    return static_cast<T>(res);
}

template <class T>
inline int solve(const T &n)
{
    return (qpow(4, n-1, 100)+qpow(2, n-1, 100))%100;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    unsigned long long n;
    while (cin >> T && T) {
        for (int i = 1; i <= T; ++i) {
            cin >> n;
            cout << "Case " << i << ": "
                 << solve(n) << endl;
        }
        cout << endl;
    }
    return 0;
}