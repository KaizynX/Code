#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+7;
const int M = 1e6+7;
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

int T, n, m, tot, rest;
int nex[M], fir[N], to[M], vis[N];
mint ans;

inline void add_edge(int u, int v)
{
    to[++tot] = v; nex[tot] = fir[u]; fir[u] = tot;
}

inline void init()
{
    tot = 0;
    ans = 1;
    rest = m;
    for (int i = 1; i <= n; ++i) fir[i] = vis[i] = 0;
}

inline mint qpow(mint a, int p)
{
    mint res = 1;
    while (p) {
        if (p&1) res = res*a;
        p >>= 1;
        a *= a;
    }
    return res;
}

void dfs(int u, int dep)
{
    if (vis[u]) {
        int len = dep-vis[u];
        if (len < 3) return; // two-loop
        ans *= qpow(2, len)-1;
        rest -= len;
        return;
    }
    vis[u] = dep;
    for (int i = fir[u], v; i; i = nex[i]) {
        v = to[i];
        dfs(v, dep+1);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    init();
    for (int i = 1, u, v; i <= m; ++i) {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) dfs(i, 1);
    }
    ans *= qpow(2, rest);
    cout << ans << endl;
    return 0;
}
