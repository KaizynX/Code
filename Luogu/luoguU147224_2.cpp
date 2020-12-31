/*
 * @Author: Kaizyn
 * @Date: 2020-12-26 21:32:03
 * @LastEditTime: 2020-12-26 22:25:22
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
const int N = 2e5+7;

struct Node {
  int x, t;
  bool operator <(const Node &b) const { return x < b.x; }
};

template <typename T>
struct BinaryIndexedTree {
  int n;
  vector<T> tr;
  void init(const int &n) { tr = vector<T>(this->n = n+1, 0); }
  void update(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] = max(tr[i], v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res = max(res, tr[i]); return res; }
};

template <typename T>
void discrete(T &a) {
  auto d = a;
  sort(d.begin(), d.end());
  d.erase(unique(d.begin(), d.end()), d.end());
  for (auto &i : a) i = lower_bound(d.begin(), d.end(), i)-d.begin()+1;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int n, k, res = 0;
  BinaryIndexedTree<int> tree;
  cin >> n >> k;
  vector<Node> a(n);
  vector<ll> val(n);
  for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].t;
  sort(a.begin(), a.end());
  // x[i]-x[j] <= k(t[i]-t[j]) --> x[i]-k*t[i] <= x[j]-k*t[j]
  for (int i = 0; i < n; ++i) val[i] = a[i].x-1ll*k*a[i].t;
  discrete(val);
  for (int i = 0; i < n; ++i) val[i] = n-val[i]+1;
  tree.init(n);
  for (int i = 0; i < n; ++i) {
    int dp = tree.query(val[i])+1;
    tree.update(val[i], dp);
    res = max(res, dp);
  }
  // x[j]-x[i] <= k(t[i]-t[j]) --> x[i]+k*t[i] >= x[j]+k*t[j]
  for (int i = 0; i < n; ++i) val[i] = a[i].x+1ll*k*a[i].t;
  discrete(val);
  tree.init(n);
  for (int i = n-1; i >= 0; --i) {
    int dp = tree.query(val[i])+1;
    tree.update(val[i], dp);
    res = max(res, dp);
  }

  cout << res << endl;
  return 0;
}