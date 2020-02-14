#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
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

int n;
mint S[N][N], A[N], pow2[N];

inline void init()
{
    A[0] = pow2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        A[i] = A[i-1]*i;
        pow2[i] = pow2[i-1]*2;
    }
    S[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            S[i][j] = S[i-1][j-1]+S[i-1][j]*j;
        }
    }
}

inline mint C(int p, int q)
{
    return A[p]/A[p-q]/A[q];
}

signed main()
{
    cin >> n;
    init();
    mint res = 1;
    for (int m = 1; m <= n; ++m) {
        for (int i = 0; i <= m; ++i) {
            res += S[n][m]*C(m, i)*pow2[m-i];
#ifdef DEBUG
            cout << m << " " << i << " " << res << " "
                 << S[n][m] << " " << C(m, i) << " " << pow2[m-i] << endl;
#endif
        }
    }
    cout << res << endl;
    return 0;
}
