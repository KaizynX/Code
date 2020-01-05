#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;
const int MOD = 10007;

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
int w[N], u[N], v[N];
vector<int> e[N];
mint s[N];

int main()
{
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> u[i] >> v[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    for (int i = 1; i < n; ++i) {
        e[u[i]].emplace_back(w[v[i]]);
        e[v[i]].emplace_back(w[u[i]]);
        s[u[i]] += w[v[i]];
        s[v[i]] += w[u[i]];
    }
    int mv = 0;
    mint res = 0;
    for (int i = 1; i <= n; ++i) {
        if (e[i].size() < 2) continue;
        sort(e[i].begin(), e[i].end());
        reverse(e[i].begin(), e[i].end());
        mv = max(mv, e[i][0]*e[i][1]);
        for (int j : e[i]) 
            res += (s[i]-j)*j;
    }
    cout << mv << " " << res << endl;
    return 0;
}
