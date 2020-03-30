/*
 * @Author: Kaizyn
 * @Date: 2020-03-28 12:08:44
 * @LastEditTime: 2020-03-28 12:15:47
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

// #define DEBUG

using namespace std;

const int MOD = 1e4+7;
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

/*
inline int solve(const int &n)
{
    static const int inv = qpow(4, MOD-2);
    return (qpow(3, n)+2-(n&1))*inv%MOD;
}
*/
template <class T>
inline int solve(const T &n)
{
    return (qpow(4, n-1)+qpow(2, n-1))%MOD;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1, n;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}