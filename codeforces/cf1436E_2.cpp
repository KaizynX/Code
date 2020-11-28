/*
 * @Author: Kaizyn
 * @Date: 2020-10-24 23:19:12
 * @LastEditTime: 2020-10-25 00:09:56
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

struct Query {
  int l, r, v;
};

template <typename T>
struct BinaryIndexedTree {
  int n;
  T tr[N];
  BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
  void init(const int &_n) { n = _n; clear(); }
  void clear() { memset(tr+1, 0, sizeof(T)*n); }
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

int n, m, block;
int a[N], check[N], cnt[N];
vector<int> p[N];
Query q[N*3];
BinaryIndexedTree<int> tree;

bool cmp(const Query &q1, const Query &q2) {
  return q1.l/block != q2.l/block ? q1.l < q2.l :
      (q1.l/block)&1 ? q1.r < q2.r : q1.r > q2.r;
}

void update(int x, int v) {
  if (v == 1) {
    if (++cnt[x] == 1) tree.add(x, 1);
  } else {
    if (--cnt[x] == 0) tree.add(x, -1);
  }
}

#ifdef DEBUG
template<typename T>
void print(T *a, int n) {
  for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
  cout.flush();
}
#endif

inline int solve() {
  cin >> n;
  tree.init(n);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[a[i]].emplace_back(i);
  }
  for (int i = 2; i <= n; ++i) {
    if (!p[i].size()) {
      q[++m] = Query{1, n, i};
      continue;
    }
    if (p[i].front() > 1) q[++m] = Query{1, p[i].front()-1, i};
    if (p[i].back()  < n) q[++m] = Query{p[i].back()+1, n, i};
    for (int j = 1; j < (int)p[i].size(); ++j) {
      if (p[i][j-1]+1 != p[i][j]) q[++m] = Query{p[i][j-1]+1, p[i][j]-1, i};
    }
  }
  block = n/sqrt(m)+1;
  sort(q+1, q+m+1, cmp);
  for (int i = 1, l = 1, r = 0; i <= m; ++i) {
    while (r < q[i].r) update(a[++r], 1);
    while (l > q[i].l) update(a[--l], 1);
    while (r > q[i].r) update(a[r--], -1);
    while (l < q[i].l) update(a[l++], -1);
    check[q[i].v] |= tree.query(q[i].v-1) == q[i].v-1;
#ifdef DEBUG
    cout << l << " " << r << " " <<  q[i].v << " "
        << tree.query(q[i].v-1) << endl;
    for (int i = 1; i <= n; ++i) cout << tree.query(i) << " \n"[i==n];
    print(cnt, n);
#endif
  }
  check[1] = (int)p[1].size() != n;
  for (int i = 1; i <= n; ++i) if (!check[i]) return i;
  return n+1;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}
/*
1
1

2
2 2
*/