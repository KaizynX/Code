/*
 * @Author: Kaizyn
 * @Date: 2021-06-13 15:15:44
 * @LastEditTime: 2021-06-13 15:44:02
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e2+7;

template <typename T>
struct Martix {
  int n, m;
  T a[N][N];
  Martix(){}
  Martix(const int &_n) : n(_n), m(_n) { init(); }
  Martix(const int &_n, const int &_m) : n(_n), m(_m) { init(); }
  T* operator [] (const int &i) { return a[i]; }
  void init(const int &tag = 0) {
    for (int i = 1; i <= n; ++i) memset(a[i], 0, sizeof(T)*(n+1));
    for (int i = 1; i <= n; ++i) a[i][i] = tag;
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
  Martix inv() const {
    Martix res = *this;
    vector<int> is(n+1), js(n+1);
    for (int k = 1; k <= n; ++k) {
      for (int i = k; i <= n; ++i)
        for (int j = k; j <= n; ++j) if (res.a[i][j]) {
          is[k] = i; js[k] = j; break;
        }
      for (int i = 1; i <= n; ++i) swap(res.a[k][i], res.a[is[k]][i]);
      for (int i = 1; i <= n; ++i) swap(res.a[i][k], res.a[i][js[k]]);
      if (!res.a[k][k]) return Martix(0);
      res.a[k][k] = mul_inverse(res.a[k][k]); // get inv of number
      for (int j = 1; j <= n; ++j) if (j != k)
        res.a[k][j] = res.a[k][j]*res.a[k][k]%MOD;
      for (int i = 1; i <= n; ++i) if (i != k)
        for (int j = 1; j <= n; ++j) if (j != k)
          res.a[i][j] = (res.a[i][j]+MOD-res.a[i][k]*res.a[k][j]%MOD)%MOD;
      for (int i = 1; i <= n; ++i) if (i != k)
        res.a[i][k] = (MOD-res.a[i][k]*res.a[k][k]%MOD)%MOD;
    }
    for (int k = n; k; --k) {
      for (int i = 1; i <= n; ++i) swap(res.a[js[k]][i], res.a[k][i]);
      for (int i = 1; i <= n; ++i) swap(res.a[i][is[k]], res.a[i][k]);
    }
    return res;
  }
  T det() {
    long long res = 1;
    Martix cpy = *this;
    for (int i = 1; i <= n; ++i) {
      for (int j = i+1; j <= n; ++j) while (cpy.a[j][i]) {
        long long t = cpy.a[i][i]/cpy.a[j][i];
        for (int k = i; k <= n; ++k)
          cpy.a[i][k] = (cpy.a[i][k]+MOD-t*cpy.a[j][k]%MOD)%MOD;
        swap(cpy.a[i], cpy.a[j]);
        res = -res;
      }
      res = res*cpy.a[i][i]%MOD;
    }
    return (res+MOD)%MOD;
  }
  friend ostream& operator << (ostream &os, Martix<T> &mx) {
    for (int i = 1; i <= mx.n; ++i)
      for (int j = 1; j <= mx.m; ++j)
        os << mx[i][j] << " \n"[j==mx.m];
    return os;
  }
};

int a[2], w, h, n;
vector<int> v;
Martix<ll> m;

bool check(int x) {
  int last = 0, cnt = 0;
  for (int i = 0; i < w; ++i) {
    if (last == ((x>>i)&1)) ++cnt;
    else {
      if (cnt%a[last]) return false;
      last ^= 1;
      cnt = 1;
    }
  }
  return cnt%a[last] == 0;
}

bool check(int x, int y) {
  int lx = 0, ly = 0, cx = 0, cy = 0;
  for (int i = 0; i < w-1; ++i) {
    if (lx == ((x>>i)&1)) ++cx;
    else cx = 1, lx ^= 1;
    if (ly == ((y>>i)&1)) ++cy;
    else cy = 1, ly ^= 1;
    if (cx%a[lx] == 0 && cy%a[ly] == 0) return false;
  }
  return true;
}

inline void solve() {
  cin >> a[0] >> a[1] >> w >> h;
  v.clear();
  for (int i = 0; i < 1<<w; ++i) if (check(i)) {
    v.emplace_back(i);
#ifdef DEBUG
    cout << bitset<9>(i) << endl;
#endif
  }
  n = v.size();
  m.n = m.m = n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      m[i+1][j+1] = check(v[i], v[j]);
    }
  }
#ifdef DEBUG
  cout << m;
#endif
  m = m.pow(h-1);
#ifdef DEBUG
  cout << m;
#endif
  ll res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      res += m[i][j];
    }
    res %= MOD;
  }
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
1
2 3 9 5
*/