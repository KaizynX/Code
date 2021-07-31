/*
 * @Author: Kaizyn
 * @Date: 2021-07-31 15:34:13
 * @LastEditTime: 2021-07-31 15:53:05
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

/*
struct List {
  static const int N = 1e5+7;
  int max_len;
  int lp[N], rp[N], vis[N];
  vector<pair<int&, int>> stk;
  void init(int n) {
    stk.clear();
    max_len = 0;
    for (int i = 0; i <= n; ++i) {
      lp[i] = rp[i] = i;
      vis[i] = 0;
    }
  }
  int insert(int x, int mem = 1) { // mem是否记录到栈
    if (++vis[x] > 1) return 0;
    int llp = lp[x-1], rrp = rp[x], cnt = 0;
    if (mem) {
      stk.emplace_back(rp[llp], rp[llp]), ++cnt;
      stk.emplace_back(lp[rrp], lp[rrp]), ++cnt;
    }
    rp[llp] = rrp;
    lp[rrp] = llp;
    if (rrp-llp > max_len) {
      if (mem) stk.emplace_back(max_len, max_len), ++cnt;
      max_len = rrp-llp;
    }
    return cnt;
  }
  void pop() {
    if (stk.empty()) return;
    stk.back().first = stk.back().second;
    stk.pop_back();
  }
  void pop_all() {
    while (stk.size()) pop();
  }
};
*/

struct List {
  static const int N = 1e5+7;
  int max_len;
  int lp[N], rp[N], vis[N];
  vector<pair<int&, int>> stk;
  void init(int n) { // 初始化大小为n的空间
    stk.clear();
    max_len = 0;
    for (int i = 0; i <= n; ++i) {
      lp[i] = rp[i] = i;
      vis[i] = 0;
    }
  }
  void insert(int x, int mem = 1) { // mem是否记录到栈
    if (mem) stk.emplace_back(vis[x], vis[x]);
    if (++vis[x] > 1) return;
    int llp = lp[x-1], rrp = rp[x];
    if (mem) {
      stk.emplace_back(rp[llp], rp[llp]);
      stk.emplace_back(lp[rrp], lp[rrp]);
    }
    rp[llp] = rrp;
    lp[rrp] = llp;
    if (rrp-llp > max_len) {
      if (mem) stk.emplace_back(max_len, max_len);
      max_len = rrp-llp;
    }
  }
  void pop_all() {
    while (stk.size()) {
      stk.back().first = stk.back().second;
      stk.pop_back();
    }
  }
};

List lk;

inline void solve() {
  int n, m;
  cin >> n >> m;
  lk.init(n);
  for (int i = 1, op, x; i <= m; ++i) {
    cin >> op >> x;
    if (op == 1) lk.insert(x);
    else {
      for (int _ = x; _; --_) lk.pop_all();
    }
    cout << "max_len:" << lk.max_len << '\n';
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