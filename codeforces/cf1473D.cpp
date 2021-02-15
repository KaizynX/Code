/*
 * @Author: Kaizyn
 * @Date: 2021-02-10 13:41:32
 * @LastEditTime: 2021-02-10 14:05:55
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

int n, m;
int a[N];

template <typename T, typename U = std::greater<T>>
struct ST {
  static const int NN = (int)log2(N)+3;
  static const T INF = 1e9;
  int lg2[N];
  U cmp = U();
  T rmq[N][NN];
  ST() {
    fill(rmq[0], rmq[0]+N*NN, cmp(-INF, +INF) ? INF : -INF);
    for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
  }
  T& operator [] (const int &i) { return rmq[i][0]; }
  void init(const T &val = 0) { fill(rmq[0], rmq[0]+N*NN, val); }
  T mv(const T &x, const T &y) { return cmp(x, y) ? x : y; }
  // rmq[i][j] ==> [i, i+2^j-1]
  void build(T a[], const int &n) {
    for (int i = n; i; --i) {
      rmq[i][0] = a[i];
      for (int j = 1; j <= lg2[n-i+1]; ++j)
        rmq[i][j] =  mv(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
    }
  }
  T query(const int &l, const int &r) {
    if (r < 1) return 0; // mie~
    if (l > n) return a[n]; // mie~
    int k = lg2[r-l+1];
    return mv(rmq[l][k], rmq[r-(1<<k)+1][k]);
  }
};

ST<int, greater<int>> mx;
ST<int, less<int>> mn;

inline void solve() {
  string str;
  cin >> n >> m >> str;
  for (int i = 0; i < n; ++i) {
    a[i+1] = a[i]+(str[i] == '+' ? 1 : -1);
  }
  mx.build(a, n);
  mn.build(a, n);
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
  #endif
  for (int _ = m, l, r, lmn, lmx, rmn, rmx; _; --_) {
    cin >> l >> r;
    lmn = min(0, mn.query(1, l-1));
    lmx = max(0, mx.query(1, l-1));
    rmn = min(0, mn.query(r+1, n)-a[r])+a[l-1];
    rmx = max(0, mx.query(r+1, n)-a[r])+a[l-1];
    #ifdef DEBUG
    cout << lmn << ' ' << lmx << ' ' << rmn << ' ' << rmx << '\n';
    #endif
    cout << max(lmx, rmx)-min(lmn, rmn)+1 << '\n';
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
1
4 10
+-++
1 3
*/