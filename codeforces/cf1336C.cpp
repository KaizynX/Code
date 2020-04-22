/*
 * @Author: Kaizyn
 * @Date: 2020-04-15 22:27:29
 * @LastEditTime: 2020-04-16 14:05:42
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 3e3+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

template <int _MOD> struct Mint
{
    int v = 0;
    Mint() {}
    Mint(int _v) : v((_v%_MOD+_MOD)%_MOD) {}
    Mint(long long _v) : v(static_cast<int>((_v%_MOD+_MOD)%_MOD)) {}
    Mint operator = (const int &_v) { return *this = Mint(_v); }
    Mint operator = (const long long &_v) { return *this = Mint(_v); }
    bool operator ! () const { return !this->v; }
    bool operator < (const Mint &b) const { return v < b.v; }
    bool operator > (const Mint &b) const { return v > b.v; }
    bool operator == (const Mint &b) const { return v == b.v; }
    bool operator != (const Mint &b) const { return v != b.v; }
    bool operator <= (const Mint &b) const { return v < b.v || v == b.v; }
    bool operator >= (const Mint &b) const { return v > b.v || v == b.v; }
    Mint operator + (const Mint &b) const { return Mint(v+b.v); }
    Mint operator - (const Mint &b) const { return Mint(v-b.v); }
    Mint operator * (const Mint &b) const { return Mint(1ll*v*b.v); }
    Mint operator / (const Mint &b) const { return Mint(b.inv()*v); }
    Mint& operator += (const Mint &b) { return *this = *this+b; }
    Mint& operator -= (const Mint &b) { return *this = *this-b; }
    Mint& operator *= (const Mint &b) { return *this = *this*b; }
    Mint& operator /= (const Mint &b) { return *this = *this/b; }
    Mint operator - () const { return Mint(-v); }
    Mint& operator ++ () { return *this += 1; }
    Mint& operator -- () { return *this -= 1; }
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
char S[N], T[N];
mint suf[N], pre[N], dp[N][N];

inline void solve()
{
    scanf("%s%s", S+1, T+1);
    n = strlen(S+1);
    m = strlen(T+1);
    for (int i = 1; i <= m; ++i) if (S[1] == T[i]) dp[i][i] = 2;
    dp[0][0] = dp[m+1][m+1] = 2;
    mint res = 0;
    for (int i = 2; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (S[i] == T[j]) dp[j][m+1] += dp[j+1][m+1];
        }
        dp[m-i+2][m+1] += dp[m-i+2][m];
        for (int j = m; j; --j) {
            if (S[i] == T[j]) dp[0][j] += dp[0][j-1];
        }
        dp[0][i-1] += dp[1][i-1];
        for (int l = 1, r; (r = l+i-1) <= m; ++l) {
            if (S[i] == T[l]) dp[l][r] += dp[l+1][r];
            if (S[i] == T[r]) dp[l][r] += dp[l][r-1];
        }
        dp[0][0] *= 2;
        dp[m+1][m+1] *= 2;
        #ifdef DEBUG
        for (int i = 0; i <= m+1; ++i) cout << dp[0][i] << " \n"[i==m+1];
        for (int i = 0; i <= m+1; ++i) cout << dp[i][m+1] << " \n"[i==m+1];
        #endif
    }
    res += dp[1][m];
    for (int i = m+1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (S[i] == T[j]) dp[j][m+1] = dp[j][m+1]+dp[j+1][m+1];
        }
        for (int j = m; j; --j) {
            if (S[i] == T[j]) dp[0][j] = dp[0][j]+dp[0][j-1];
        }
        dp[0][0] *= 2;
        dp[m+1][m+1] *= 2;
        res += dp[0][m]+dp[1][m+1];
        #ifdef DEBUG
        for (int i = 0; i <= m+1; ++i) cout << dp[0][i] << " \n"[i==m+1];
        for (int i = 0; i <= m+1; ++i) cout << dp[i][m+1] << " \n"[i==m+1];
        #endif
    }
    cout << res << endl;
}

signed main()
{
    solve();
    return 0;
}