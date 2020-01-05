#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 8e2+7;
const int K = 20;
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

int n, m, k;
int a[N][N];
mint res;
mint dp[N][N][K][K];

int main()
{
#ifndef DEBUG
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
    cin >> n >> m >> k;
    ++k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j], a[i][j] %= k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k1 = 0; k1 < k; ++k1) {
                for (int k2 = 0; k2 < k; ++k2) {
                    dp[i][j][k1][k2] += dp[i-1][j][(k1-a[i][j]+k)%k][k2]+
                                        dp[i][j-1][(k1-a[i][j]+k)%k][k2]+
                                        dp[i][j-1][k1][(k2-a[i][j]+k)%k]+
                                        dp[i-1][j][k1][(k2-a[i][j]+k)%k];
                }
            }
            dp[i][j][a[i][j]][0]++;
            dp[i][j][0][a[i][j]]++;
#ifdef DEBUG
            printf("[%d, %d] ", i, j);
#endif
            for (int kk = 0; kk < k; ++kk) {
                res += dp[i][j][kk][kk];
#ifdef DEBUG
                printf("(%d, %d)%c", kk, dp[i][j][kk][kk].v, " \n"[kk==k-1]);
#endif
            }
        }
    }
    cout << res << endl;
    return 0;
}
