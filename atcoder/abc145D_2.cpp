#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

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

inline long long C(int p, int q)
{
    long long res = 1;
    for (int i = p-q+1; i <= p; ++i)
        res = res*i%MOD;
    for (int i = 2; i <= q; ++i)
        res = res*qpow(i, MOD-2)%MOD;
    return res;
}

int main()
{
    int x, y;
    cin >> x >> y;
    for (int i = 0, j; i <= x && 2*i <= y; ++i) {
        // i (1, 2)
        j = y-2*i;
        if (2*j+i == x) {
            cout << C(i+j, min(i, j)) << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}

