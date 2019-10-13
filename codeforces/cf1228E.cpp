#include <bits/stdc++.h>

using namespace std;

const int N = 250+7;
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

int n, k;
mint comb[N][N], dp[N][N], pk[N], pk1[N];
// dp[i][j] i row, j col has no 1

inline mint qpow(mint a, int p)
{
    mint res = 1;
    while (p) {
        if (p&1) res *= a;
        a *= a;
        p >>= 1;
    }
    return res;
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j <= i/2; ++j) {
            comb[i][j] = comb[i][i-j] = comb[i-1][j]+comb[i-1][j-1];
        }
    }
    pk[0] = pk1[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pk[i] = pk[i-1]*k;
        pk1[i] = pk1[i-1]*(k-1);
    }

    for (int i = 1; i <= n; ++i) {
        dp[i][0] = qpow(pk[n]-pk1[n], i);
        dp[1][i] = qpow(k, n-i);
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = (pk[n-j]-pk1[n-j])*pk1[j]*dp[i-1][j];
            for (int c = 1; c <= j; ++c) {
                dp[i][j] += pk[n-j]*comb[j][c]*pk1[j-c]*dp[i-1][j-c];
            }
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}
