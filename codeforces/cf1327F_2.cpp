/*
 * @Author: Kaizyn
 * @Date: 2020-03-25 20:48:09
 * @LastEditTime: 2020-03-25 20:53:34
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 5e5+7;
const int MOD = 998244353;
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


struct Node
{
    int l, r, x;
    friend istream& operator >> (istream &is, Node &nd) {
        return is >> nd.l >> nd.r >> nd.x;
    }
};

int n, k, m;
int add[N], last[N];
mint dp[N], sum[N];
Node a[N];

inline void solve()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= m; ++i) cin >> a[i];

    mint res = 1;
    for (int b = 0; b < k; ++b) {
        memset(add, 0, sizeof(int)*(n+3));
        memset(last, 0, sizeof(int)*(n+3));
        for (int i = 1; i <= m; ++i) {
            if ((a[i].x>>b)&1) ++add[a[i].l], --add[a[i].r+1];
            else last[a[i].r+1] = max(last[a[i].r+1], a[i].l);
        }
        for (int i = 1; i <= n+1; ++i) {
            add[i] += add[i-1];
            last[i] = max(last[i], last[i-1]);
        }
        sum[0] = dp[0] = 1;
        for (int i = 1; i <= n+1; ++i) {
            if (add[i] > 0) dp[i] = 0;
            else {
                dp[i] = sum[i-1];
                if (last[i]) dp[i] -= sum[last[i]-1];
            }
            sum[i] = sum[i-1]+dp[i];
        }
        res *= dp[n+1];
    }
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}