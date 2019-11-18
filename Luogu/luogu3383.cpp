#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(time(NULL));

template <typename T> inline void read(T &x)
{
    char c; T tag = 1;
    while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
    x = c-'0';
    while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
    x *= tag;
}

inline int qpow(int a, int p, int mo) {
    int res = 1;
    while (p) {
        if (p&1) res = static_cast<int>(1ll*res*a%mo);
        a = static_cast<int>(1ll*a*a%mo);
        p >>= 1;
    }
    return res;
}

inline bool MillerRabin(int x)
{
    static const int test_time = 10;
    if (x < 3) return x == 2;
    int a = x-1, b = 0;
    while (!(a&1)) a >>= 1, ++b;
    for (int i = 1, j, v; i <= test_time; ++i) {
        v = (qpow(rnd()%(x-2)+2, a, x));
        if (v == 1 || v == x-1) continue;
        for (j = 0; j < b && v != x-1; ++j)
            v = static_cast<int>(1ll*v*v%x);
        if (j >= b) return false;
    }
    return true;
}

int n, m;

int main()
{
    read(n); read(m);
    for (int i = 0, a; i < m; ++i) {
        read(a);
        puts(MillerRabin(a) ? "Yes" : "No");
    }
    return 0;
}
