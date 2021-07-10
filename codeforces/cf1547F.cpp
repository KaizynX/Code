/*
 * @Author: Kaizyn
 * @Date: 2021-07-10 23:15:30
 * @LastEditTime: 2021-07-10 23:20:14
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
const int N = 4e5+7;

template <typename T>
struct ST {
  static const int NN = (int)log2(N)+3;
  static const T INF = 1e9;
  int lg2[N];
  T rmq[N][NN];
  ST() {
    for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
  }
  T& operator [] (const int &i) { return rmq[i][0]; }
  // void init(const T &val = 0) { fill(rmq[0], rmq[0]+N*NN, val); }
  T mv(const T &x, const T &y) { return __gcd(x, y); }
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
int a[N];
ST<int> st;

inline void solve() {
  cin >> n;
  int g = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    g = g ? __gcd(g, a[i]) : a[i];
  }
  for (int i = 1; i <= n; ++i) {
    a[i] /= g;
    a[i+n] = a[i];
  }
  st.build(a, 2*n);
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    int l = 0, r = n-1, mid;
    while (l < r) {
      mid = (l+r)>>1;
      if (st.query(i, i+mid) == 1) r = mid;
      else l = mid+1;
    }
    res = max(res, l);
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