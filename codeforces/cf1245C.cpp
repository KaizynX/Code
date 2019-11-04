#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
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

string str;
mint f[N];
mint res = 1;

int main()
{
    cin >> str;
    f[0] = 1; f[1] = 1; f[2] = 2; f[3] = 3;
    for (int i = 2; i < N; ++i) {
        f[i] = f[i-1]+f[i-2];
    }
    for (int i = 0; i < (int)str.length(); ++i) {
        if (str[i] == 'm' || str[i] == 'w') {
            res = 0;
            break;
        }
        if (str[i] != 'n' && str[i] != 'u') continue;
        char c = str[i];
        int cnt = 1;
        while (i+1 < (int)str.length() && str[i+1] == c) {
            ++i;
            ++cnt;
        }
        res *= f[cnt];
    }
    cout << res << endl;
    return 0;
}
