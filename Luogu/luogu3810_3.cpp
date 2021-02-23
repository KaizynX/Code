/*
 * @Author: Kaizyn
 * @Date: 2021-02-17 15:34:48
 * @LastEditTime: 2021-02-17 16:22:39
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

template <typename T>
struct BinaryIndexedTree {
  int n;
  vector<T> tr;
  void init(const int &n) { this->n = n; clear(); }
  void clear() { tr = vector<T>(n+1, 0); }
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

struct Node {
  int x, y, z, w, f;
  bool operator <(const Node &b) const {
    return vector<int>({x, y, z}) < vector<int>({b.x, b.y, b.z});
  }
  bool operator !=(const Node &b) const {
    return vector<int>({x, y, z}) != vector<int>({b.x, b.y, b.z});
  }
};

int n, m, k;
int res[N];
Node a[N], b[N];
BinaryIndexedTree<int> tree;

void cdq(int l, int r) {
  if (l >= r) return;
  int mid = (l+r)>>1, i = l, j = mid+1;
  cdq(l, mid); cdq(mid+1, r);
  for (int k = l; k <= r; ++k) {
    if (j > r || (i <= mid && a[i].y <= a[j].y)) {
      tree.add(a[i].z, a[i].w);
      b[k] = a[i++];
    } else {
      a[j].f += tree.query(a[j].z);
      b[k] = a[j++];
    }
  }
  for (int k = l; k <= mid; ++k) tree.add(a[k].z, -a[k].w);
  for (int k = l; k <= r; ++k) a[k] = b[k];
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> b[i].x >> b[i].y >> b[i].z;
  }
  sort(b+1, b+n+1);
  for (int i = 1; i <= n; ++i) {
    if (b[i] != a[m]) {
      a[++m] = b[i];
    }
    ++a[m].w;
  }
  tree.init(k);
  cdq(1, m);
  for (int i = 1; i <= m; ++i) {
    res[a[i].f+a[i].w-1] += a[i].w;
  }
  for (int i = 0; i < n; ++i) {
    cout << res[i] << '\n';
  }
  return 0;
}