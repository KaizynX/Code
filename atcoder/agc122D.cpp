#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
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

int n;
mint res;
mint dp[N][4][4][4];
// len i'th i-1 i-2
// 0123 ACGT

int main()
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                dp[3][i][j][k] = 1;
    dp[3][1][2][0] = dp[3][2][1][0] = dp[3][1][0][2] = 0;

    cin >> n;
    for (int l = 4; l <= n; ++l) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    if (  (i == 1 && j == 2 && k == 0)
                        ||(i == 2 && j == 1 && k == 0)
                        ||(i == 1 && j == 0 && k == 2))
                        continue;
                    for (int h = 0; h < 4; ++h) {
                        if (  (i == 1 && j == 2 && h == 0)
                            ||(i == 1 && k == 2 && h == 0)
                            ||(j == 1 && k == 2 && h == 0))
                            continue;
                        dp[l][i][j][k] += dp[l-1][j][k][h];
                    }
                }
            }
        }
        /*
        for (int i = 0; i < 4; ++i) {
            // AXGC
            dp[l][1][2][i] -= dp[l-1][2][i][0];
            // AGXC
            dp[l][1][i][2] -= dp[l-1][i][2][0];
        }
        dp[l][1][2][0] = dp[l][2][1][0] = dp[l][1][0][2] = 0;
        */
    }
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                res += dp[n][i][j][k];
    cout << res << endl;
    return 0;
}
