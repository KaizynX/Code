/*
 * @Author: Kaizyn
 * @Date: 2021-02-17 17:11:45
 * @LastEditTime: 2021-02-17 19:56:38
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

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

struct Node {
  int t, v, p;
};

int n, m;
ll res[N];
Node a[N], b[N];
BinaryIndexedTree<int> tree;

void cdq(int l, int r) {
  if (l >= r) return;
  int mid = (l+r)>>1;
  cdq(l, mid); cdq(mid+1, r);
  int i = l, j = mid+1;
  for (int k = l; k <= r; ++k) {
    if (j > r || (i <= mid && a[i].v > a[j].v)) {
      tree.add(a[i].p, 1);
      b[k] = a[i++];
    } else {
      res[a[j].t] += tree.query(a[j].p-1);
      b[k] = a[j++];
    }
  }
  for (int k = l; k <= mid; ++k) tree.add(a[i].p, -1);
  for (int k = l; k <= r; ++k) a[k] = b[k];
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    a[i].p = i;
    cin >> a[i].v;
  }
  for (int i = 1, x; i <= m; ++i) {
    cin >> x;
    a[x].t = n-i+1;
  }
  for (int i = 1, j = 0; i <= n; ++i) {
    if (a[i].t == 0) a[i].t = ++j;
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    printf("a[%d]={%d,%d,%d}\n", i, a[i].t, a[i].v, a[i].p);
  }
  #endif
  sort(a+1, a+n+1, [](auto &x, auto &y) {
    return x.t < y.t;
  });
  tree.init(n);
  cdq(1, n);
  for (int i = 1; i <= n; ++i) res[i] += res[i-1];
  for (int i = n, j = m; j; --i, --j) cout << res[i] << '\n';
  return 0;
}