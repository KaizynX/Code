/*
 * @Author: Kaizyn
 * @Date: 2020-05-09 15:28:43
 * @LastEditTime: 2020-05-09 16:17:23
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int MOD = 1e9+7;
const int N = 3e4+7;

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

int n, m, t;
int a[N], cnt[N], inv[N];
int res[N];

struct Node {
  int l, r, id;
  friend bool operator < (const Node &lhs, const Node &rhs) {
    return lhs.l/t == rhs.l/t ? lhs.r < rhs.r : lhs.l < rhs.l;
  }
} q[N];

inline void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cnt[a[i]] = 0;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> q[i].l >> q[i].r;
    --q[i].l; --q[i].r;
    q[i].id = i;
  }
  t = static_cast<int>(sqrt(n)+.5);
  sort(q+1, q+m+1);
  int l = 0, r = -1; // [l, r]
  mint cur = 1;
  for (int i = 1; i <= m; ++i) {
    while (r < q[i].r) {
      cur *= inv[++cnt[a[++r]]];
      cur *= r-l+1;
    }
    while (r > q[i].r) {
      cur *= inv[r-l+1];
      cur *= cnt[a[r--]]--;
    }
    while (l > q[i].l) {
      cur *= inv[++cnt[a[--l]]];
      cur *= r-l+1;
    }
    while (l < q[i].l) {
      cur *= inv[r-l+1];
      cur *= cnt[a[l++]]--;
    }
    res[q[i].id] = cur.v;
  }
  for (int i = 1; i <= m; ++i) cout << res[i] << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  inv[0] = inv[1] = 1;
  for(int i = 2; i < N; ++i)
    inv[i] = 1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}