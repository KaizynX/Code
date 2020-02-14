#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int k, m;
int a[N];

struct Rt
{
    int sz = 10;
    long long v[N][N];
    Rt(int tag = 0) {
        memset(v, 0, sizeof v);
        if (tag == 1) for (int i = 0; i < sz; ++i) v[i][i] = 1;
        if (tag == 2) {
            for (int i = 0; i < sz-1; ++i) v[i][i+1] = 1;
            for (int i = 0; i < sz; ++i) v[sz-1][i] = a[i];
        }
    }
    friend Rt operator * (const Rt &r1, const Rt &r2) {
        Rt res;
        for (int i = 0; i < res.sz; ++i)
            for (int j = 0; j < res.sz; ++j)
                for (int k = 0; k < res.sz; ++k)
                    (res.v[i][j] += r1.v[i][k]*r2.v[k][j]) %= m;
        return res;
    }
    Rt qpow(int p) {
        Rt res(1), a = *this;
        while (p) {
            if (p&1) res = res*a;
            a = a*a;
            p >>= 1;
        }
        return res;
    }
};

int main()
{
    while (cin >> k >> m) {
        for (int i = 0; i < 10; ++i)
            cin >> a[i];
        if (k < 10) { cout << k%m << endl; continue; }
        reverse(a, a+10);
        Rt rt(2);
        rt = rt.qpow(k-9);
        long long res = 0;
        for (int i = 0; i < 10; ++i)
            (res += i*rt.v[9][i]%m) %= m;
        cout << res << endl;
    }
    return 0;
}
