/*
 * @Author: Kaizyn
 * @Date: 2020-06-06 15:47:57
 * @LastEditTime: 2020-06-06 17:17:38
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

template <typename T, typename U = std::greater<T>>
struct ST {
  static const int NN = (int)log2(N)+3;
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

int n, L;
int p[N], v[N], pre_sum[N];
ST<int> st;

inline void solve() {
  cin >> n >> L;
  int beg = 0, res = -INF;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    if (p[i] < 0) beg = i;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
    pre_sum[i] = pre_sum[i-1]+v[i];
  }
  st.build(pre_sum, n);

  if (p[beg] != -1 || p[beg+1] != 1) res = max(res, 0);
  // start at 0
  for (int i = beg; i; --i) {
    if (L < -p[i]) break;
    res = max(res, pre_sum[beg]-pre_sum[i-1]);
  }
  for (int i = beg+1; i <= n; ++i) {
    if (L < p[i]) break;
    res = max(res, pre_sum[i]-pre_sum[beg]);
  }
  // 0 -> p[i] -> 0 -> right
  for (int i = 1, r; i <= beg; ++i) {
    if (L+2*p[i] < 0) continue;
    r = upper_bound(p+beg+1, p+n+1, L+2*p[i])-p-1;
    res = max(res, st.query(beg, r)-pre_sum[i-1]);
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}