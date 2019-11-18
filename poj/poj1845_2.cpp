#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 9901;

template <int _MOD> struct Mint
{
    int v;
    Mint() { v = 0; }
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
#define mint Mint<MOD>

template <typename T> inline T qpow(T x, long long p) {
    T res = 1;
    for ( ; p; p >>= 1, x *= x)
        if (p&1) res *= x;
    return res;
}

template <typename T> inline T mul_inv(T x) {
    return qpow(x, MOD-2);
}

int a, b;

int main()
{
    while (cin >> a >> b) {
        vector<pair<int, int> > v;
        for (int i = 2, k; i*i <= a; ++i) {
            if (a%i) continue;
            for (k = 0; a%i == 0; a /= i, ++k) {}
            v.push_back({i, k});
        }
        if (a > 1) v.push_back({a, 1});

        mint res = 1;
        for (int i = 0; i < (int)v.size(); ++i) {
            // (q^(n+1)-1)/q-1
            if ((v[i].first-1)%MOD == 0) res *= (mint)v[i].first*b*v[i].second+1;
            else res *= (qpow((mint)v[i].first, 1ll*b*v[i].second+1)-1)*mul_inv((mint)v[i].first-1);
        }
        cout << res << endl;
    }
    return 0;
}
