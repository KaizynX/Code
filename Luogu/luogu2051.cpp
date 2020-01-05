#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 9999973;

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
// dp[i][i1][i2] at row i has i1 cols with 1 point, has i2 cols with 2 points
mint dp[N][N][N], c[N][N];

inline void init()
{
    for (int i = 1; i <= m; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j <= i/2; ++j)
            c[i][j] = c[i][i-j] = c[i-1][j-1]+c[i-1][j];
    }
}

int main()
{
    cin >> n >> m;
    init();
    mint res = 0;
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int i1 = 0; i1 <= m; ++i1) {
            for (int i2 = 0; i1+i2 <= m; ++i2) {
                mint &now = dp[i][i1][i2];
                now = dp[i-1][i1][i2];
                if (i1 >= 1) now += dp[i-1][i1-1][i2]*c[m-i1-i2+1][1];
                if (i1 >= 2) now += dp[i-1][i1-2][i2]*c[m-i1-i2+2][2];
                if (i2 >= 1) now += dp[i-1][i1+1][i2-1]*c[i1+1][1];
                if (i2 >= 2) now += dp[i-1][i1+2][i2-2]*c[i1+2][2];
                if (i1 >= 1 && i2 >= 1) now += dp[i-1][i1][i2-1]*c[i1][1]*c[m-i1-i2+1][1];

                if (i == n) res += now;
#ifdef DEBUG
                printf("dp[%d][%d][%d] = %d\n", i, i1, i2, now.v);
#endif
            }
        }
    }
    cout << res << endl;
    return 0;
}
