#include <bits/stdc++.h>

using namespace std;

const int N = 1e2;
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
int a[N][2][3];
mint dp[2][N][N][N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                cin >> a[i][j][k];
            }
        }
    }
    dp[0][50][50][50] = 1;
    mint res = 0;
    for (int t = 1; t <= n; ++t) {
        for (int i0 = 1; i0 < 100; ++i0)
        for (int i1 = 1; i1 < 100; ++i1)
        for (int i2 = 1; i2 < 100; ++i2) {
            mint &now = dp[t&1][i0][i1][i2];
            now = 0;
            for (int j = 0; j < 2; ++j) {
                if (i0-a[t][j][0] > 0 && i0-a[t][j][0] < 100 &&
                    i1-a[t][j][1] > 0 && i1-a[t][j][1] < 100 &&
                    i2-a[t][j][2] > 0 && i2-a[t][j][2] < 100)
                    now += dp[t-1&1][i0-a[t][j][0]][i1-a[t][j][1]][i2-a[t][j][2]];
            }
            if (t == n) res += now;
        }
    }
    cout << res << endl;
    return 0;
}
