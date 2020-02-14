#include <bits/stdc++.h>

using namespace std;

const int N = 15;
const int MOD = 9973;

int T, n, k;

struct Rt
{
    int sz;
    int a[N][N];
    Rt(int _sz = 0) : sz(_sz) {
        memset(a, 0, sizeof a);
        for (int i = 0; i < _sz; ++i)
            a[i][i] = 1;
    }
    friend Rt operator * (const Rt &r1, const Rt &r2) {
        Rt res;
        res.sz = r1.sz;
        for (int i = 0; i < res.sz; ++i)
            for (int j = 0; j < res.sz; ++j)
                for (int k = 0; k < res.sz; ++k)
                    (res.a[i][j] += r1.a[i][k]*r2.a[k][j]%MOD) %= MOD;
        return res;
    }
    Rt qpow(int p) {
        Rt res(this->sz), a = *this;
        while (p) {
            if (p&1) res = res*a;
            a = a*a;
            p >>= 1;
        }
        return res;
    }
    int tr() {
        int res = 0;
        for (int i = 0; i < this->sz; ++i)
            (res += this->a[i][i]) %= MOD;
        return res;
    }
};

int main()
{
    cin >> T;
    while (T--) {
        Rt rt;
        cin >> n >> k;
        rt.sz = n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n ; ++j)
                cin >> rt.a[i][j];
        rt = rt.qpow(k);
        cout << rt.tr() << endl;
    }
    return 0;
}
