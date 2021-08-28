/*
 * @Author: Kaizyn
 * @Date: 2021-08-28 16:16:53
 * @LastEditTime: 2021-08-28 16:29:01
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;
namespace hjt {
template<typename A,typename B>
std::ostream &operator<<(std::ostream &o,const std::pair<A,B> &x){
  return o<<'('<<x.first<<','<<x.second<<')';
}
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define qwq [&]{cerr<<"qwq"<<endl;}()
#define orz(x) [&]{cerr<<#x": "<<x<<endl;}()
#define orzarr(a,n) [&]{cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}()
#define orzeach(a) [&]{cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}()
#define pause [&]{system("pause");}()
} using namespace hjt;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}

template <typename T>
struct Martix {
  int n, m;
  T a[3][3];
  Martix(){}
  Martix(const int &_n) : n(_n), m(_n) { init(); }
  Martix(const int &_n, const int &_m) : n(_n), m(_m) { init(); }
  T* operator [] (const int &i) { return a[i]; }
  void init(const int &tag = 0) {
    for (int i = 1; i <= n; ++i) memset(a[i], 0, sizeof(T)*(m+1));
    if (tag) for (int i = 1; i <= n; ++i) a[i][i] = tag;
  }
  friend Martix operator * (const Martix &m1, const Martix &m2) {
    Martix res(m1.n, m2.m);
    for (int i = 1; i <= res.n; ++i)
      for (int j = 1; j <= res.m; ++j)
        for (int k = 1; k <= m1.m; ++k)
          res.a[i][j] = (res.a[i][j]+m1.a[i][k]*m2.a[k][j])%MOD;
    return res;
  }
  Martix& operator *= (const Martix &mx) { return *this = *this*mx; }
  Martix& operator + (const Martix &mx) const { Martix res(n, m); return res += mx; }
  Martix& operator += (const Martix &mx) {
    assert(n == mx.n && m == mx.m);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        a[i][j] += mx.a[i][j];
    return *this;
  }
  Martix& operator - (const Martix &mx) const { Martix res(n, m); return res -= mx; }
  Martix& operator -= (const Martix &mx) {
    assert(n == mx.n && m == mx.m);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        a[i][j] -= mx.a[i][j];
    return *this;
  }
  template <typename TT>
  Martix pow(const TT &p) const {
    Martix res(n, m), a = *this;
    res.init(1);
    for (TT i = p; i; i >>= 1, a *= a) if (i&1) res *= a;
    return res;
  }
  friend ostream& operator << (ostream &os, const Martix<T> &mx) {
    for (int i = 1; i <= mx.n; ++i)
      for (int j = 1; j <= mx.m; ++j)
        os << mx.a[i][j] << " \n"[j==mx.m];
    return os;
  }
};

struct Combination {
  int fac[N], inv[N];
  void init(const int &n) {
    fac[0] = inv[0] = fac[1] = inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
      fac[i] = 1ll*fac[i-1]*i%MOD;
      inv[i] = 1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
    }
    for (int i = 2; i <= n; ++i) {
      inv[i] = 1ll*inv[i]*inv[i-1]%MOD;
    }
  }
  int A(const int &p, const int &q) {
    return p >= q ? 1ll*fac[p]*inv[p-q]%MOD : 0;
  }
  int C(const int &p, const int &q) {
    return p >= q ? 1ll*fac[p]*inv[q]%MOD*inv[p-q]%MOD : 0;
  }
};

namespace NTT { // array [0, n)
const int SIZE = (1<<18)+3;
const int G = 3;
int len, bit;
int rev[SIZE];
long long f[SIZE], g[SIZE];
template <class T>
void ntt(T a[], int flag = 1) {
  for (int i = 0; i < len; ++i)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int base = 1; base < len; base <<= 1) {
    long long wn = qpow(G, (MOD-1)/(base*2)), w;
    if (flag == -1) wn = qpow(wn, MOD-2);
    for (int i = 0; i < len; i += base*2) {
      w = 1;
      for (int j = 0; j < base; ++j) {
        long long x = a[i+j], y = w*a[i+j+base]%MOD;
        a[i+j] = (x+y)%MOD;
        a[i+j+base] = (x-y+MOD)%MOD;
        w = w*wn%MOD;
      }
    }
  }
}
template <class T>
void work(T a[], const int &n, T b[], const int &m) {
  len = 1; bit = 0;
  while (len < n+m) len <<= 1, ++bit;
  for (int i = 0; i < n; ++i) f[i] = a[i];
  for (int i = n; i < len; ++i) f[i] = 0;
  for (int i = 0; i < m; ++i) g[i] = b[i];
  for (int i = m; i < len; ++i) g[i] = 0;
  for (int i = 0; i < len; ++i)
    rev[i] = (rev[i>>1]>>1)|((i&1)<<(bit-1));
  ntt(f, 1); ntt(g, 1);
  for (int i = 0; i < len; ++i) f[i] = f[i]*g[i]%MOD;
  ntt(f, -1);
  long long inv = qpow(len, MOD-2);
  for (int i = 0; i < n+m-1; ++i) f[i] = f[i]*inv%MOD;
}
} // namespace NTT

int n, a, b, c, d, e;
int g1[N], g2[N], h1[N], h2[N];
ll f[N];
Martix<ll> mat, matp;
Combination comb;
int *fac = comb.fac, *inv = comb.inv;

inline void solve() {
  cin >> n >> a >> b >> c >> d >> e;
  mat.n = mat.m = 2;
  mat[1][1] = d; mat[1][2] = e; mat[2][1] = 1; mat[2][2] = 0;
  matp = mat;
  for (int i = 0; i < n; ++i, matp *= mat) {
    g1[i] = matp[1][1]*inv[i+1]%MOD;
    g2[i] = matp[1][2]*inv[i+1]%MOD;
  }
  mat[1][1] = b; mat[1][2] = c; mat[2][1] = 1; mat[2][2] = 0;
  matp = mat;
  h1[0] = 1; h2[0] = 0;
  for (int i = 1; i < n; ++i, matp *= mat) {
    h1[i] = matp[1][1]*inv[i+1]%MOD;
    h2[i] = matp[2][1]*inv[i+1]%MOD;
  }
  NTT::work(g1, n, h1, n);
  for (int i = 0; i < n+n; ++i) f[i] = NTT::f[i];
  NTT::work(g2, n, h2, n);
  for (int i = 0; i < n+n; ++i) f[i] += NTT::f[i];
  ll ans = 0;
  for (int i = 0; i < n+n; ++i) ans += f[i]*fac[i+2]%MOD;
  ans = ans%MOD*a%MOD;
  cout << ans << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  comb.init(N-1);
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}