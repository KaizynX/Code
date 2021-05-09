/*
 * @Author: Kaizyn
 * @Date: 2021-05-06 21:51:04
 * @LastEditTime: 2021-05-06 22:31:06
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 4e2+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

void print(vector<int> &v) {
  for (int &i : v) cout << i << ' ';
  cout << endl;
}

template <typename T>
T exgcd(const T a, const T b, T &x, T &y)
{
    if (!b) { x = 1; y = 0; return a; }
    T d = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

template <typename T>
inline T mul_inverse(const T &a, const T &mo = MOD)
{
    T x, y;
    exgcd(a, mo, x, y);
    return (x%mo+mo)%mo;
}

template <typename U>
class Martix {
 public:
  Martix() {}
  Martix(const int &_n, const int &_m = 1) : n(_n), m(_m) {
    a = vector<vector<U>>(n, vector<U>(m, 0));
  }
  bool empty() const { return n == 0 || m == 0; }
  vector<U>& operator [] (const int &i) { return a[i]; }
  void I(const int &_n) {
    n = m = _n;
    a = vector<vector<U>>(n, vector<U>(n, 0));
    for (int i = 0; i < n; ++i) a[i][i] = 1;
  }
  Martix T() const {
    Martix t(m, n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        t[j][i] = a[i][j];
    return t;
  }
  friend Martix operator *(const Martix &m1, const Martix &m2) {
    assert(m1.m == m2.n);
    Martix res(m1.n, m2.m);
    for (int i = 0; i < res.n; ++i)
      for (int j = 0; j < res.m; ++j)
        for (int k = 0; k < m1.m; ++k)
          res[i][j] += m1.a[i][k]*m2.a[k][j]; // MOD
    return res;
  }
  Martix& operator *=(const Martix &mx) { return *this = *this*mx; }
  template <typename TT>
  Martix pow(const TT &p) const {
    assert(n == m);
    Martix res(n, m), a = *this;
    res.I(n);
    for (TT i = p; i; i >>= 1, a *= a) if (i&1) res *= a;
    return res;
  }
  Martix inv() const {
    assert(n == m);
    Martix res = *this;
    vector<int> is(n, -1), js(n, -1);
    for (int k = 0; k < n; ++k) {
      for (int i = k; i < n; ++i)
        for (int j = k; j < n; ++j) if (res[i][j]) {
          is[k] = i; js[k] = j; break;
        }
      if (is[k] == -1) return Martix(0);
      swap(res[k], res[is[k]]);
      // for (int i = 0; i < n; ++i) swap(res[k][i], res[is[k]][i]);
      for (int i = 0; i < n; ++i) swap(res[i][k], res[i][js[k]]);
      res[k][k] = mul_inverse(res[k][k]); // get inv of number
      for (int j = 0; j < n; ++j) if (j != k)
        res[k][j] = res[k][j]*res[k][k]%MOD;
      for (int i = 0; i < n; ++i) if (i != k)
        for (int j = 0; j < n; ++j) if (j != k)
          res[i][j] = (res[i][j]+MOD-res[i][k]*res[k][j]%MOD)%MOD;
      for (int i = 0; i < n; ++i) if (i != k)
        res[i][k] = (MOD-res[i][k]*res[k][k]%MOD)%MOD;
    }
    for (int k = n-1; k >= 0; --k) {
      swap(res[k], res[js[k]]);
      // for (int i = 0; i < n; ++i) swap(res[js[k]][i], res[k][i]);
      for (int i = 0; i < n; ++i) swap(res[i][is[k]], res[i][k]);
    }
    return res;
  }
  U det() {
    long long res = 1;
    Martix cpy = *this;
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) while (cpy[j][i]) {
        long long t = cpy[i][i]/cpy[j][i];
        for (int k = i; k < n; ++k)
          cpy[i][k] = (cpy[i][k]+MOD-t*cpy[j][k]%MOD)%MOD;
        swap(cpy[i], cpy[j]);
        res = -res;
      }
      res = res*cpy[i][i]%MOD;
    }
    return (res+MOD)%MOD;
  }
  template <typename TT>
  friend ostream& operator <<(ostream &os, const Martix<TT> &mx) {
    for (int i = 0; i < mx.n; ++i)
      for (int j = 0; j < mx.m; ++j)
        os << mx.a[i][j] << " \n"[j==mx.m-1];
    return os;
  }
 private:
  int n, m;
  vector<vector<U>> a;
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    Martix<long long> mx(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mx[i][j];
        }
    }
    mx = mx.inv();
    if (mx.empty()) cout << "No Solution" << endl;
    else cout << mx;
    return 0;
}
/*
3
3 2 4
7 2 9
2 4 3
*/
/*
3
1 2 8
2 5 6
5 1 2
*/