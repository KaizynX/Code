/*
 * @Author: Kaizyn
 * @Date: 2020-03-28 19:32:21
 * @LastEditTime: 2020-03-28 20:48:49
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
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

int n;
int num[N];
mint fac[N], inv[N], res[N];
vector<int> e[N];
vector<mint> w[N];

inline mint C(const int &p, const int &q)
{
    return fac[p]*inv[q]*inv[p-q];
}

int dfs1(const int &u, const int &fa)
{
    num[u] = 0;
    for (int i = 0, v; i < (int)e[u].size(); ++i) {
        v = e[u][i];
        if (v == fa) continue;
        dfs1(v, u);
        num[u] += num[v];
    }
    for (int i = 0, v, sum = num[u]; i < (int)e[u].size(); ++i) {
        v = e[u][i];
        if (v == fa) continue;
        w[u][i] = C(sum, num[v])*res[v];
        res[u] *= w[u][i];
        sum -= num[v];
    }
    return ++num[u]; // itself
}

void dfs2(const int &u, const int &fa, const mint &val)
{
    for (int i = 0, v; i < (int)e[u].size(); ++i) {
        v = e[u][i];
        if (v == fa) continue;
        mint tmp = res[u]/(C(num[u]-1, num[v])*res[v]);
        tmp *= val*C(n-num[v]-1, n-num[u]);
        dfs2(v, u, tmp);
    }
    res[u] *= C(n-1, n-num[u])*val;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = fac[i-1]*i;
        inv[i] = fac[i].inv();
    }
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        w[i].resize(e[i].size(), 0);
        res[i] = 1;
    }
    dfs1(1, 0);
    dfs2(1, 0, 1);
    for (int i = 1; i <= n; ++i) cout << res[i] << endl;
    return 0;
}