#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
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
mint pow2[N];
vector<int> e[N], son[N];

int dfs(int u, int fa)
{
    int fi = -1, sum = 0;
    for (int i = 0, v; i < (int)e[u].size(); ++i) {
        v = e[u][i];
        if (v == fa) {
            fi = i;
            continue;
        }
        son[u][i] = dfs(v, u);
        sum += son[u][i];
    }
    if (fi != -1) son[u][fi] = n-1-sum;
    return sum+1;
}

int main()
{
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    pow2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        son[i].resize(e[i].size(), 0);
        pow2[i] = pow2[i-1]*2;
    }
    dfs(1, 0);
    mint res = 0;
#ifdef DEBUG
    for (int i = 1; i <= n; ++i) {
        for (int j : son[i]) cout << j << " ";
        cout << endl;
    }
#endif
    for (int i = 1; i <= n; ++i) {
        mint mul = 1;
        /*
        for (int j = 0; j < (int)son[i].size(); ++j) {
            mul *= son[i][j];
            res -= son[i][j];
        }
        */
        for (int j : son[i]) {
            mul *= pow2[j];
            res -= pow2[j];
        }
        res += mul+(int)son[i].size()-1;
    }
    cout << res/pow2[n] << endl;
    return 0;
}
