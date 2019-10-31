#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const int MOD = 1e4+7;

struct FenKuai
{
    typedef int T;
    int t, sz;
    static const int NN = static_cast<int>(sqrt(N))+7;
    T a[N], sum[NN], tag_add[NN], tag_mul[NN];

    void init(int _n)
    {
        sz = _n;
        t = static_cast<int>(sqrt(sz)+0.5);
        for (int i = 0; i < sz; ++i) {
            sum[i/t] = (sum[i/t]+a[i])%MOD;
            tag_add[i/t] = 0;
            tag_mul[i/t] = 1;
        }
    }

    void modify(int x)
    {
        if (tag_add[x] == 0 && tag_mul[x] == 1) return;
        for (int i = x*t; i < min(x*t+t, sz); ++i) a[i] = (a[i]*tag_mul[x]+tag_add[x])%MOD;
        tag_add[x] = 0; tag_mul[x] = 1;
    }

    void add(int x, int y, T k)
    {
        int i = x;
        modify(x/t); for ( ; i <= y && i%t; ++i) (a[i]+=k)%=MOD, (sum[i]+=k)%=MOD;
        for ( ; i+t-1 <= y; i += t) (tag_add[i/t]+=k)%=MOD, (sum[i]+=k*t)%=MOD;
        modify(y/t); for ( ; i <= y; ++i) (a[i]+=k)%=MOD, (sum[i]+=k)%=MOD;
    }

    void mul(int x, int y, int k)
    {
        int i = x;
        modify(x/t); for ( ; i <= y && i%t; ++i) (a[i]*=k)%=MOD, (sum[i]+=a[i]*(k-1))%=MOD;
        for ( ; i+t-1 <= y; i += t) (tag_mul[i/t]*=k)%=MOD, (tag_add[i/t]*=k)%=MOD, (sum[i]*=k)%=MOD;
        modify(y/t); for ( ; i <= y; ++i) (a[i]*=k)%=MOD, (sum[i]+=a[i]*(k-1))%=MOD;
    }

    T query(int x) { return (a[x]*tag_mul[x/t]+tag_add[x/t])%MOD; }
    T query(int x, int y)
    {
        T res = 0;
        int i  = x;
        for ( ; i <= y && i%t; ++i) (res += a[i]*tag_mul[i/t]+tag_add[i/t])%=MOD;
        for ( ; i+t-1 <= y; i += t) (res+=sum[i/t])%=MOD;
        for ( ; i <= y; ++i) (res += a[i]*tag_mul[i/t]+tag_add[i/t])%=MOD;
        return res;
    }
} B;

int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) cin >> B.a[i];
    B.init(n);
    for (int i = 0, op, l, r, c; i < n; ++i) {
        cin >> op >> l >> r >> c;
        --l; --r;
        if (op == 0) {
            B.add(l, r, c);
        } else if (op == 1) {
            B.mul(l, r, c);
        } else {
            cout << B.query(r) << endl;
        }
    }
    return 0;
}
