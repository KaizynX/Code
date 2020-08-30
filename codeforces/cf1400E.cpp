/*
 * @Author: Kaizyn
 * @Date: 2020-08-26 00:16:53
 * @LastEditTime: 2020-08-26 00:29:29
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e3+7;

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
    if (l > r) return INF;
    int k = lg2[r-l+1];
    return mv(rmq[l][k], rmq[r-(1<<k)+1][k]);
  }
};

int n;
int a[N];
int dp[N][N];
ST<int, less<int>> st1, st2;

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  memset(dp, 0x3f, sizeof dp);
  dp[0][0+1] = 0;
  st1.build(dp[0], n+1);
  st2.build(dp[0], n+1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n && j <= a[i]; ++j) {
      /*
      for (int k = 0; k <= n; ++k) {
        if (k >= j) dp[i][j] = min(dp[i][j], dp[i-1][j]);
        if (k < j) dp[i][j] = min(dp[i][j], dp[i-1][j]+j-k);
      }
      */
      dp[i][j+1] = min(dp[i][j+1], st1.query(j+1, n+1));
      dp[i][j+1] = min(dp[i][j+1], st2.query(0+1, j-1+1)+j);
      if (j < a[i]) ++dp[i][j+1];
    }
    st1.build(dp[i], n+1);
    for (int j = 0; j <= n; ++j) dp[i][j+1] -= j;
    st2.build(dp[i], n+1);
  }
  cout << st1.query(0+1, n+1) << endl;
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