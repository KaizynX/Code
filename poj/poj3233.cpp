#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e2+7;

int n, k, m;

struct Rt
{
    int sz;
    int a[N][N];
    Rt(int _sz = 0, int tag = 0) : sz(_sz) {
        memset(a, 0, sizeof a);
        if (tag == 2) for (int i = 0; i < sz; ++i)
            a[i][i+sz] = a[i+sz][i+sz] = 1;
        else if (tag == 1) for (int i = 0; i < sz*2; ++i)
            a[i][i] = 1;
    }
    friend Rt operator * (const Rt &r1, const Rt &r2) {
        Rt res(r1.sz, 0);
        for (int i = 0; i < res.sz*2; ++i)
            for (int j = 0; j < res.sz*2; ++j)
                for (int k = 0; k < res.sz*2; ++k)
                    (res.a[i][j] += r1.a[i][k]*r2.a[k][j]%m) %= m;
        return res;
    }
    Rt qpow(int p) {
        Rt res(this->sz, 1), b = *this;
        while (p) {
            if (p&1) res = res*b;
            b = b*b;
            p >>= 1;
        }
        return res;
    }
} rt;

int main()
{
    cin >> n >> k >> m;
    rt = Rt(n, 2);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> rt.a[i][j], rt.a[i][j] %= m;
    rt = rt.qpow(k+1);
    for (int i = 0; i < n; ++i)
            rt.a[i][i+n] = (rt.a[i][i+n]-1+m)%m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cout << rt.a[i][j+n] << " \n"[j==n-1];
    return 0;
}
