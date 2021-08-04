/*
 * @Author: Kaizyn
 * @Date: 2021-08-01 16:25:45
 * @LastEditTime: 2021-08-01 16:29:19
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

struct DSU {
  vector<int> fa;
  void init(int n) { fa = vector<int>(n+1); iota(fa.begin(), fa.end(), 0); }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    return x == y ? false : fa[x] = y, true;
  }
};

int n;
DSU dsu;

inline void solve() {
  cin >> n;
  dsu.init(n);
  int cnt = 0;
  for (int i = 1, a; i <= n; ++i) {
    cin >> a;
    cnt += dsu.merge(a, i);
  }
  cout << (cnt%2 ? "First" : "Second") << '\n';
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