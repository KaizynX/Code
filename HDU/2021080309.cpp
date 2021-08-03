/*
 * @Author: Kaizyn
 * @Date: 2021-08-03 12:15:18
 * @LastEditTime: 2021-08-03 12:18:51
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
const int N = 3e6+7;

template <typename T>
struct BinaryIndexedTree {
  int n;
  vector<T> tr;
  void init(const int &n) { this->n = n; tr = vector<T>(n+1, 0); }
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

int n;
int a[N];
vector<int> v[N];
BinaryIndexedTree<int> tree;

inline void solve() {
  cin >> n;
  tree.init(n);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    v[a[i]].emplace_back(i);
  }
  for (int i = 0; i <= 1000'000; ++i) if (v[i].size()) {
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
    for (int i = 1; i <= n; ++i) {
      v[a[i]].clear();
    }
  }
  return 0;
}