#include <bits/stdc++.h>
#define DEBUG

using namespace std;

#ifndef DEBUG
const int MAXN = 32000+7;
#else
const int MAXN = 1e2+7;
#endif
const int MOD = 998244353;

int n, k;
int a[MAXN], f[MAXN];

struct Martix
{
    int m[MAXN][MAXN];
    
    Martix(int arg = 0)
    {
        for (int i = 0; i <= k; ++i) 
            for (int j = 0; j <= k; ++j)
                m[i][j] = 0;

        // µ¥Î»¾ØÕó
        if (!arg) {
            for (int i = 0; i <= k; ++i) 
                m[i][i] = 1;
        } else {
            for (int i = 1; i < k; ++i) {
                m[i][i+1] = 1;
            }
            for (int i = 1; i <= k; ++i) {
                m[k][i] = f[k-i+1];
            }
        }
    }

    Martix operator * (const Martix b)
    {
        Martix res;
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= k; ++j) {
                res.m[i][j] = 0;
                for (int l = 1; l <= k; ++l) {
                    res.m[i][j] += static_cast<int>( (1ll*this->m[i][l]*b.m[l][j])%MOD );
                    res.m[i][j] %= MOD;
                }
            }
        }
        return res;
    }
};

ostream& operator << (ostream &os, Martix mx)
{
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            os << mx.m[i][j] << " ";
        }
    }
    os << endl;
    return os;
}

inline Martix qpow(Martix mx, int p)
{
    Martix res;
    while (p)
    {
        if (p&1) res = res*mx;
        p >>= 1;
        mx = mx*mx;
    }
    return res;
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> f[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    // special judge
    if (n < k) {
        cout << a[n] << endl;
        return 0;
    }

    int res = 0;
    Martix base = qpow(Martix(1), n-k+1);
    for (int i = 0; i < k; ++i) {
        res += static_cast<int>( (1ll*a[i]*base.m[k][i+1])%MOD );
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}
