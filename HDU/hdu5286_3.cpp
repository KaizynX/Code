/*
 * @Author: Kaizyn
 * @Date: 2020-05-12 17:10:44
 * @LastEditTime: 2020-05-13 15:36:44
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int MOD = 1e9+7;
const int N = 5e4+7;
const int NN = sqrt(N)+7;

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

int n, q, t, m;
int a[N], cnt[N], dis[N];
vector<mint> pw[N];
int sum[NN][N]; // sum[i][j] the num of j in [0, i*t)
mint f[NN][NN]; // f[i][j] the res of [i*t, j*t+t)

inline void discrete() {
  memcpy(dis, a, sizeof(int)*n);
  sort(dis, dis+n);
  m = unique(dis, dis+n)-dis;
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(dis, dis+m, a[i])-dis;
  }
}

inline void get_pow() {
  memset(cnt, 0, sizeof(int)*m);
  for (int i = 0; i < n; ++i) ++cnt[a[i]];
  for (int i = 0; i < m; ++i) {
    pw[i].resize(cnt[i]+1);
    pw[i][0] = 1;
    for (int j = 1; j <= cnt[i]; ++j) {
      pw[i][j] = pw[i][j-1]*dis[i];
    }
    pw[i][0] = 0;
  }
  memset(cnt, 0, sizeof(int)*m);
}

inline void init_st() {
  memset(sum, 0, sizeof sum);
  memset(f, 0, sizeof f);
  /*
  for (int i = 0; i < n/t; ++i) {
    memset(sum[i+1], 0, sizeof(int)*m);
    memset(f[i], 0, sizeof(mint)*(n/t));
  }
  */
  for (int i = 0; i < n; ++i) ++sum[i/t+1][a[i]];
  for (int i = 1; i <= n/t+1; ++i) {
    for (int j = 0; j < m; ++j) {
      sum[i][j] += sum[i-1][j];
    }
  }
  for (int i = 0; i <= n/t; ++i) {
    for (int j = i*t; j < n; ++j) {
      f[i][j/t] -= pw[a[j]][cnt[a[j]]];
      f[i][j/t] += pw[a[j]][++cnt[a[j]]];
    }
    memset(cnt, 0, sizeof(int)*m);
    // for (int j = i*t; j < n; ++j) cnt[a[j]] = 0;
    for (int j = i+1; j <= n/t; ++j) f[i][j] += f[i][j-1];
  }
}

inline int query(const int &l, const int &r) {
  mint res = 0;
  if (l/t == r/t) {
    for (int i = l; i <= r; ++i) {
      res -= pw[a[i]][cnt[a[i]]];
      res += pw[a[i]][++cnt[a[i]]];
    }
    for (int i = l; i <= r; ++i) cnt[a[i]] = 0;
    return res.v;
  }
  int ll = l/t+(l%t != 0), rr = r/t-(r%t != t-1);
  res = f[ll][rr];
  for (int i = l; i%t; ++i) cnt[a[i]] = sum[rr+1][a[i]]-sum[ll][a[i]];
  for (int i = r; i%t != t-1; --i) cnt[a[i]] = sum[rr+1][a[i]]-sum[ll][a[i]];
  for (int i = l; i%t; ++i) {
    res -= pw[a[i]][cnt[a[i]]];
    res += pw[a[i]][++cnt[a[i]]];
  }
  for (int i = r; i%t != t-1; --i) {
    res -= pw[a[i]][cnt[a[i]]];
    res += pw[a[i]][++cnt[a[i]]];
  }
  for (int i = l; i%t; ++i) cnt[a[i]] = 0;
  for (int i = r; i%t != t-1; --i) cnt[a[i]] = 0;
  return res.v;
}

inline void solve() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) scanf("%d", a+i);

  t = sqrt(n)+.5;
  discrete();
  get_pow();
  init_st();

  for (int i = 1, l, r, res = 0; i <= q; ++i) {
    scanf("%d %d", &l, &r);
    l = (l^res)%n;
    r = (r^res)%n;
    #ifdef DEBUG
    cout << "(" << l << ", " << r << ")" << endl;
    #endif
    if (l > r) swap(l, r);
    printf("%d\n", res = query(l ,r));
  }
  for (int i = 0; i < m; ++i) vector<mint>().swap(pw[i]);
}

signed main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}