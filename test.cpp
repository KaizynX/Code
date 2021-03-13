/*
 * @Author: Kaizyn
 * @Date: 2020-03-03 16:51:41
 * @LastEditTime: 2021-03-12 22:33:17
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
// const int N = ;

template <typename T = int> struct DSU {
  vector<int> fa;
  vector<T> w;
  void init(int n, T v = 1) {
    fa = vector<int>(n+1);
    iota(fa.begin(), fa.end(), 0);
    w = vector<T>(v);
  }
  void init(int n, T a[]) {
    fa = vector<int>(n+1);
    iota(fa.begin(), fa.end(), 0);
    w = vector<T>(a, a+n+1);
  }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    return x == y ? false : w[y] += w[x], fa[x] = y, true;
  }
};

DSU dsu;

inline void solve() {
  cout << (0 == 0U) << '\n';
  cout << (-1 < 0) << '\n';
  cout << (-1 < 0U) << '\n';
  cout << (2147483647 > -2147483647-1) << '\n';
  cout << (2147483647U > -2147483647-1) << '\n';
  cout << (2147483647 > (int)2147483648U) << '\n';
  cout << (-1 > -2) << '\n';
  cout << ((unsigned)-1 > -2) << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}