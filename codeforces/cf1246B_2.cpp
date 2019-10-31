#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int M = 1e4+7;
const int C[2] = { 23, 31 };
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

int n, k, cnt;
bool check[N];
int a[N], prime[M], fp[N];
mint my_hash[2][N], rev_hash[2][N];
long long res;
map<pair<int, int>, int> mp;

inline void init()
{
    check[1] = true;
    for(int i = 2; i < N; ++i)
    {
        if(!check[i]) {
            ++cnt;
            prime[cnt] = i;
            fp[i] = cnt;
        }
        for(int j = 1; j <= cnt && i*prime[j] < N; ++j)
        {
            check[ i*prime[j] ] = true;
            if(i % prime[j] == 0) break;
        }
    }
}

inline mint qpow(mint a, int p)
{
    mint res = 1;
    while (p) {
        if (p&1) res *= a;
        a *= a;
        p >>= 1;
    }
    return res;
}

int main()
{
    cin >> n >> k;
    init();
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        // 分解质因数
        for (int j = 1, pi; prime[j]*prime[j] <= a[i]; ++j) {
            if (a[i]%prime[j]) continue;
            pi = 0;
            while (a[i]%prime[j] == 0) a[i] /= prime[j], ++pi;
            pi %= k;
            // a[i] = sum prime[j]^pi
            // hash = sum c^j*pi
            for (int h = 0; h < 2; ++h) {
                my_hash[h][i] += qpow(C[h], j)*pi;
                rev_hash[h][i] += qpow(C[h], j)*((k-pi)%k);
            }
        }
        if (a[i] > 1) {
            for (int h = 0, j = fp[a[i]], pi = 1; h < 2; ++h) {
                my_hash[h][i] += qpow(C[h], j)*pi;
                rev_hash[h][i] += qpow(C[h], j)*((k-pi)%k);
            }
        }
        res += mp[{rev_hash[0][i].v, rev_hash[1][i].v}];
        ++mp[{my_hash[0][i].v, my_hash[1][i].v}];
    }
    cout << res << endl;
    return 0;
}
