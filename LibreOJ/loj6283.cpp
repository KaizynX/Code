#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const int MOD = 1e4+7;

template <int _MOD> struct Mint
{
    int v = 0;
    Mint() {}
    Mint(int _v) : v((_v%_MOD+_MOD)%_MOD) {}
    Mint(long long _v) : v(static_cast<int>((_v%_MOD+_MOD)%_MOD)) {}
    Mint operator = (const int _v) { this->v = _v; return *this; }
    Mint operator = (const long long _v) { this->v = static_cast<int>(_v%_MOD); return *this; }
    bool operator < (const Mint &b) const { return v < b.v; }
    bool operator > (const Mint &b) const { return v > b.v; }
    bool operator == (const Mint &b) const { return v == b.v; }
    bool operator != (const Mint &b) const { return v != b.v; }
    bool operator <= (const Mint &b) const { return v < b.v || v == b.v; }
    bool operator >= (const Mint &b) const { return v > b.v || v == b.v; }
    Mint operator + (const Mint &b) { return Mint(v+b.v); }
    Mint operator - (const Mint &b) { return Mint(v-b.v); }
    Mint operator * (const Mint &b) { return Mint(1ll*v*b.v); }
    Mint operator / (const Mint &b) { return Mint(b.inv()*v); }
    Mint operator += (const Mint &b) { return *this = *this+b; }
    Mint operator -= (const Mint &b) { return *this = *this-b; }
    Mint operator *= (const Mint &b) { return *this = *this*b; }
    Mint operator /= (const Mint &b) { return *this = *this/b; }
    Mint pow(int p) const {
        Mint res(1), x(*this);
        while (p) {
            if (p&1) res = res*x;
            x *= x;
            p >>= 1;
        }
        return res;
    }
    Mint inv() const { return pow(_MOD-2); }
    friend istream& operator >> (istream &is, Mint &mt) { return is >> mt.v; }
    friend ostream& operator << (ostream &os, const Mint &mt) { return os << mt.v; }
};
using mint = Mint<MOD>;

struct FenKuai
{
    typedef mint T;
    int t, sz;
    static const int NN = static_cast<int>(sqrt(N))+7;
    T a[N], sum[NN], tag_add[NN], tag_mul[NN];

    void init(int _n)
    {
        sz = _n;
        t = static_cast<int>(sqrt(sz)+0.5);
        for (int i = 0; i < sz; ++i) {
            a[i] %= MOD; ///
            sum[i/t] += a[i];
            tag_add[i/t] = 0;
            tag_mul[i/t] = 1;
        }
    }

    void modify(int x)
    {
        if (tag_add[x] == 0 && tag_mul[x] == 1) return;
        for (int i = x*t; i < min(x*t+t, sz); ++i) a[i] = a[i]*tag_mul[x]+tag_add[x];
        tag_add[x] = 0; tag_mul[x] = 1;
    }

    void add(int x, int y, T k)
    {
        int i = x;
        modify(x/t); for ( ; i <= y && i%t; ++i) a[i] += k, sum[i] += k;
        for ( ; i+t-1 <= y; i += t) tag_add[i/t] += k, sum[i] += k*t;
        modify(y/t); for ( ; i <= y; ++i) a[i] += k, sum[i] += k;
    }

    void mul(int x, int y, int k)
    {
        int i = x;
        modify(x/t); for ( ; i <= y && i%t; ++i) a[i] *= k, sum[i] += a[i]*(k-1);
        for ( ; i+t-1 <= y; i += t) tag_mul[i/t] *= k, tag_add[i/t] *= k, sum[i] *= k;
        modify(y/t); for ( ; i <= y; ++i) a[i] *= k, sum[i] += a[i]*(k-1);
    }

    T query(int x) { return a[x]*tag_mul[x/t]+tag_add[x/t]; }
    T query(int x, int y)
    {
        T res = 0;
        int i  = x;
        for ( ; i <= y && i%t; ++i) res += a[i]*tag_mul[i/t]+tag_add[i/t];
        for ( ; i+t-1 <= y; i += t) res += sum[i/t];
        for ( ; i <= y; ++i) res += a[i]*tag_mul[i/t]+tag_add[i/t];
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
