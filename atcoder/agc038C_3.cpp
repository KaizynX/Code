#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;
const int V = 1e6;
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

int n;
mint res;
mint w[V+7], s[V+7], p[V+7];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 1; i <= V; ++i) {
        w[i] += mint(i).inv();
        for (int j = i+i; j <= V; j += i)
            w[j] -= w[i];
    }

    cin >> n;
    for (int i = 1, a; i <= n; ++i) {
        cin >> a;
        s[a] += a;
        p[a] += 1ll*a*a%MOD;
    }
    for (int i = 1; i <= V; ++i) {
        mint x, y;
        for (int j = i; j <= V; j += i)
            x += s[j], y += p[j];
        res += w[i]*(x*x-y);
    }
    res /= 2;
    cout << res << endl;
    return 0;
}
