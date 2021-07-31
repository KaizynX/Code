/*
 * @Author: Kaizyn
 * @Date: 2021-07-31 12:16:09
 * @LastEditTime: 2021-07-31 12:24:21
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

template <typename T, typename U = std::greater<T>>
struct ST {
  static const int NN = 20;
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
    if (l > r) return query(r, l);
    int k = lg2[r-l+1];
    return mv(rmq[l][k], rmq[r-(1<<k)+1][k]);
  }
};

int n, m;
int a[N];
ST<int, greater<int>> mx;
ST<int, less<int>> mn;

inline int f(int l, int r) {
  return mx.query(l, r)-mn.query(l, r);
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  mx.build(a, n);
  mn.build(a, n);
  for (int i = 1, k; i <= m; ++i) {
    cin >> k;
    ll cnt = n*(n+1ll)/2;
    for (int r = 1, l = 1; r <= n; ++r) {
      while (l <= r && f(l, r) > k) ++l;
      // cnt -= (r-l+1ll)*(r-l+2ll)/2;
      cnt -= r-l+1;
      #ifdef DEBUG
      printf("(%d,%d)=%d, cnt=%lld\n", l, r, l <= r ? f(l, r) : -1, cnt);
      #endif
    }
    cout << cnt << '\n';
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}