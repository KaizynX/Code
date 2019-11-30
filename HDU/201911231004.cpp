#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 1e9+7;

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

int n, m;
mint A[N], f[N], s[N], pow10[N];
string str;

inline mint qpow(mint a, int p) {
    mint res = 1;
    for ( ; p; p >>= 1, a *= a)
        if (p&1) res *= a;
    return res;
}

inline mint mul_inv(mint a) { return qpow(a, MOD-2); }

inline mint C(int p, int q) { // C_p^q
    if (p < 0 || q < 0 || p < q) return 0;
    return A[p]*mul_inv(A[p-q])*mul_inv(A[q]);
}

inline void init(const int n, const int m)
{
    for (int i = 0; i <= n-m-1; ++i) {
        f[i] = pow10[i]*C(n-i-2, m-1);
        s[i] = (i > 0 ? s[i-1] : 0)+f[i];
    }
    for (int i = n-m; i < n; ++i) {
        f[i] = 0;
        s[i] = s[i-1];
    }
}

int main()
{
    A[0] = pow10[0] = 1;
    for (int i = 1; i <= 100000; ++i) {
        A[i] = A[i-1]*i;
        pow10[i] = pow10[i-1]*10;
    }

    while (cin >> n >> m) {
        cin >> str;
        if (m == 0) {
            cout << str << endl;
            continue;
        }
        init(n, m);
        mint res = 0;
#ifdef DEBUG
        for (int i = 0; i < n; ++i)
            cout << f[i] << " ";
        cout << endl;
#endif
        for (int i = 0; i < n; ++i) {
            res += ((n-i-2 >= 0 ? s[n-i-2] : 0)+pow10[n-i-1]*C(i, m))*(str[i]-'0');
        }
        cout << res << endl;
    }
    return 0;
}
