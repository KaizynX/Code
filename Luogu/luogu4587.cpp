/*
 * @Author: Kaizyn
 * @Date: 2021-06-08 22:57:57
 * @LastEditTime: 2021-06-08 23:32:42
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
    if (l > r) return query(r, l);
    int k = lg2[r-l+1];
    return mv(rmq[l][k], rmq[r-(1<<k)+1][k]);
  }
};

int n, m;
int a[N], s[N], b[N];
ST<int, greater<int>> st;

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s[i] = s[i-1]+a[i];
    b[i] = a[i]-s[i-1];
  }
  st.build(b, n);
  cin >> m;
  for (int i = 1, l, r, L, R, mid; i <= m; ++i) {
    cin >> L >> R;
    l = L; r = R;
    while (l < r) {
      mid = (l+r+1)/2;
      if (st.query(L, mid)+s[L-1] <= 1) l = mid;
      else r = mid-1;
    }
#ifdef DEBUG
    cout << l << ": ";
#endif
    cout << s[l]-s[L-1]+1 << '\n';
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