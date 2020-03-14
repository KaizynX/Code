/*
 * @Author: Kaizyn
 * @Date: 2020-03-13 17:40:22
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-13 17:58:07
 * @FilePath: \Code\Luogu\luogu4781.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e3+7;
const int MOD = 998244353;
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

template <typename T>
inline T mul_inverse(const T &a, const int &mo = MOD)
{
    return qpow(a, mo-2);
}

template <typename T, typename H, typename P>
long long Largrange(const T &k, const int &n, const H x[], const P y[])
{
    long long res = 0, t = 1;
    for (int i = 1; i <= n; ++i, t = 1) {
        for (int j = 1; j <= n; ++j) if (i != j)
            t = t*(x[i]-x[j]+MOD)%MOD;
        t = mul_inverse(t);
        for (int j = 1; j <= n; ++j) if (i != j)
            t = t*(k-x[j]+MOD)%MOD;
        res = (res+t*y[i]%MOD)%MOD;
    }
    return res;
}

int n, k;
int x[N], y[N];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
    cout << Largrange(k, n, x, y) << endl;
    return 0;
}