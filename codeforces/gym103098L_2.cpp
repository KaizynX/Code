/*
 * @Author: Kaizyn
 * @Date: 2021-10-24 13:35:54
 * @LastEditTime: 2021-10-24 14:45:42
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
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 10;

template <typename T>
struct Martix {
  int n, m;
  T a[N][N];
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

Martix<ll> a;
ll f[10];

inline ll solve() {
  ll n;
  cin >> n;
  if (n == 1) return 1;
  if (n == 2) return 3;
  /*
  if (n == 3) return 10;
  a.n = a.m = 7;
  a.init();
  a[1][1] = 1;
  a[1][2] = 2;
  a[1][3] = 5;
  a[1][4] = 2;
  a[1][6] = 4;
  a[1][7] = 2;
  a[2][1] = 1;
  a[3][2] = 1;
  a[4][3] = 1;
  a[5][6] = 1;
  a[6][7] = 1;
  a[7][4] = 1;
  a[7][5] = 1;
  a = a.pow(n-3);
  // cout << a;
  ll ans = 0;
  for (int i = 1; i <= 7; ++i) {
    (ans += f[i]*a[1][i]) %= MOD;
  }
  */
  a.n = a.m = 6;
  a.init();
  a[1][1] = 1;
  a[1][3] = 1;
  a[1][4] = 2;
  a[1][5] = 4;
  a[1][6] = 2;
  a[2][1] = 1;
  a[3][2] = 1;
  a[4][5] = 1;
  a[5][6] = 1;
  a[6][1] = 1;
  a[6][4] = 1;
  a = a.pow(n-2);
  ll ans = 0;
  for (int i = 1; i <= 6; ++i) ans += f[i]*a[1][i];
  return ans%MOD;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  memset(f, 0, sizeof f);
  /*
  f[1] = 10;
  f[2] = 3;
  f[3] = 1;
  f[4] = 1;
  */
  f[1] = 3;
  f[2] = 1;
  f[3] = 1;
  f[5] = 1;
  f[6] = 1;
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << solve() << '\n';
  }
  return 0;
}