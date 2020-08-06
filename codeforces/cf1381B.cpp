/*
 * @Author: Kaizyn
 * @Date: 2020-07-21 22:33:02
 * @LastEditTime: 2020-07-22 00:04:46
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 4e3+3;

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

int n;
int p[N];
bitset<2048> dp[2][N];
ST<int> st;

inline bool solve() {
  cin >> n;
  for (int i = 1; i <= 2*n; ++i) cin >> p[i];
  p[n*2+1] = n*2+1;
  st.build(p, 2*n+1);
  dp[0][0].reset();
  dp[1][0].reset();
  dp[0][0].set(0);
  dp[1][0].set(0);
  for (int i = 1; i <= n*2; ++i) {
    dp[0][i].reset();
    dp[1][i].reset();
    for (int j = i; j; --j) {
      // int k = st.query(j, i+1);
      if (st.query(j, i+1) == p[i+1]) {
        dp[0][i] |= dp[1][j-1]<<(i-j+1);
        dp[1][i] |= dp[0][j-1];
      }
    }
    #ifdef DEBUG
    for (int j = 0; j <= 2; ++j) cout << dp[0][i][j] << " \n"[j==2];
    for (int j = 0; j <= 2; ++j) cout << dp[1][i][j] << " \n"[j==2];
    cout << endl;
    #endif
  }
  return dp[0][n*2][n]|dp[1][n*2][n];
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}