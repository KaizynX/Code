#include <bits/stdc++.h>

using namespace std;

const int N = 1e9+7;
const int MOD = 1e9+7;

int n, m;

inline int qpow(int a, int p)
{
    int res = 1;
    while (p) {
        if (p&1) res = static_cast<int>((1ll*a*res)%MOD);
        a = static_cast<int>((1ll*a*a)%MOD);
        p >>= 1;
    }
    return res;
}

int main()
{
    cin >> n >> m;
    cout << qpow((qpow(2, m)-1+MOD)%MOD, n) << endl;
    return 0;
}
