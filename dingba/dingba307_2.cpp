#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const int MOD = 998244353;

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
    Mint operator - () { return Mint(-v); }
    Mint &operator ++ () { return *this += 1; }
    Mint &operator -- () { return *this -= 1; }
    Mint operator ++ (int) { Mint tmp = *this; *this += 1; return tmp; }
    Mint operator -- (int) { Mint tmp = *this; *this -= 1; return tmp; }
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

int n, len = 1, bit;
mint S[N], A[N], pow2[N], inv[N], f[N], g[N];
int rev[N];

template <typename T>
inline T qpow(T a, int p)
{
    T res = 1;
    while (p) {
        if (p&1) res *= a;
        a *= a;
        p >>= 1;
    }
    return res;
}

inline mint C(int p, int q)
{
    return A[p]/A[p-q]/A[q];
}

template <typename T>
inline void NTT(T a[], int flag)
{
    for (int i = 0; i < len; ++i)
        if (i < rev[i]) swap(a[i], a[rev[i]]);

    for (int base = 1; base < len; base <<= 1) {
        T wn = qpow(G, (MOD-1)/(base*2)), w;
        if (flag == -1) wn = qpow(wn, MOD-2);
        for (int i = 0; i < len; i += base*2) {
            w = 1;
            for (int j = 0; j < base; ++j) {
                T x = a[i+j], y = w*a[i+j+base];
                a[i+j] = x+y;
                a[i+j+base] = x-y;
                w = w*wn;
            }
        }
    }
}

void stirling(const int &n)
{
    inv[0] = inv[1] = 1;
    for(int i = 2; i <= n; ++i)
        inv[i] = MOD-MOD/i*inv[MOD%i];
    for (int i = 1; i <= n; ++i)
        inv[i] = inv[i-1]*inv[i];
    while (len <= (n<<1)) len <<= 1, ++bit;
    for (int i = 0; i < len; ++i)
        rev[i] = (rev[i>>1]>>1)|((i&1)<<(bit-1));
    for (int i = 0, one = 1; i <= n; ++i, one = MOD-one) {
        f[i] = one*inv[i];
        g[i] = qpow(i, n)*inv[i];
    }
    NTT(f, 1); NTT(g, 1);
    for (int i = 0; i < len; ++i) f[i] = f[i]*g[i];
    NTT(f, -1);
    mint invv = qpow(len, MOD-2);
    for (int i = 0; i <= n; ++i)
        S[i] = f[i]*invv;
}

inline void init()
{
    A[0] = pow2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        A[i] = A[i-1]*i;
        pow2[i] = pow2[i-1]*2;
    }
    stirling(n);
}

signed main()
{
    cin >> n;
    init();
    mint res = 0;
    for (int i = 0; i <= n; ++i) {
        f[i] = S[i]*A[i];
    }
    cout << res << endl;
    return 0;
}
