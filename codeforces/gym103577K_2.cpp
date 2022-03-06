/*
 * @Author: Kaizyn
 * @Date: 2022-03-05 14:30:51
 * @LastEditTime: 2022-03-05 17:15:57
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;
namespace hjt {
template<typename A,typename B>
std::ostream &operator<<(std::ostream &o,const std::pair<A,B> &x){
  return o<<'('<<x.first<<','<<x.second<<')';
}
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define qwq [&]{cerr<<"qwq"<<endl;}()
#define orz(x) [&]{cerr<<#x": "<<x<<endl;}()
#define orzarr(a,n) [&]{cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}()
#define orzeach(a) [&]{cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}()
#define pause [&]{system("pause");}()
} using namespace hjt;

#define int ll
typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
// const int INF = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 4e5 + 7;

struct Node {
  int x, y, id;
  bool operator < (const Node &rhs) const {
    return x < rhs.x;
  }
};

template <typename T, typename U = greater<T>>
struct SegmentTree {
  SegmentTree(){}
  void build(const int &_n, const T &k = 0) { n = _n; _build(1, n, k); }
  template <typename TT>
  void buiil(const int _n, const TT a[]) { n = _n; _build(1, n, a); }
  void modify(const int &x, const T &k) { _modify(x, x, k); }
  void modify(const int &l, const int &r, const T &k) { _modify(l, r, k); }
  void add(const int &x, const T &k) { _add(x, k); }
  T query(const int &x) { return _query(x, x); }
  T query(const int &l, const int &r) { return _query(l, r); }
private:
  struct TreeNode
  {
    int l, r;
    T v, lazy;
  } tr[N<<2];
  int n;
  T init_val = cmp(0, 1) ? INF : -INF;
  U cmp = U();
  T mv(const T &x, const T &y) { return cmp(x, y) ? x : y;}
  void update(const int &i, const T &k) { tr[i].v = mv(tr[i].v, k); tr[i].lazy = mv(tr[i].lazy, k); }
  void push_up(const int &i) { tr[i].v = mv(tr[i<<1].v, tr[i<<1|1].v); }
  void push_down(const int &i) {
    if (tr[i].lazy == init_val) return;
    update(i<<1, tr[i].lazy);
    update(i<<1|1, tr[i].lazy);
    tr[i].lazy = init_val;
  }
  void _build(const int &l, const int &r, const T &k = 0, const int &i = 1) {
    tr[i].lazy = init_val;
    tr[i].l = l; tr[i].r = r;
    if (l == r) { tr[i].v = k; return; }
    int mid = (l+r)>>1;
    _build(l, mid, k, i<<1);
    _build(mid+1, r, k, i<<1|1);
    push_up(i);
  }
  template <typename TT>
  void _build(const int &l, const int &r, const TT a[], const int &i = 1) {
    tr[i].lazy = init_val;
    tr[i].l = l; tr[i].r = r;
    if (l == r) { tr[i].v = a[l]; return; }
    int mid = (l+r)>>1;
    _build(l, mid, a, i<<1);
    _build(mid+1, r, a, i<<1|1);
    push_up(i);
  }
  void _modify(const int &l, const int &r, const T &k, const int &i = 1) {
    if (tr[i].l  >= l && tr[i].r <= r) { update(i, k); return; }
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    if (l <= mid) _modify(l, r, k, i<<1);
    if (r >  mid) _modify(l, r, k, i<<1|1);
    push_up(i);
  }
  void _add(const int &x, const T &k, const int &i = 1) {
    if (tr[i].l == x && tr[i].r == x) { tr[i].v += k; return; }
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    if (x <= mid) _add(x, k, i<<1);
    else _add(x, k, i<<1|1);
    push_up(i);
  }
  T _query(const int &l, const int &r, const int &i = 1) {
    if (tr[i].l  >= l && tr[i].r <= r) return tr[i].v;
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    T res = init_val;
    if (l <= mid) res = mv(res, _query(l, r, i<<1));
    if (r >  mid) res = mv(res, _query(l, r, i<<1|1));
    return res;
  }
};

int n, m;
Node fd[N], le[N];
int ans[N];
vector<int> set_y;
SegmentTree<int, less<int>> tree_a, tree_m;

void update(int &x, int y) {
  if (x == -1 || y < x) x = y;
}

template <typename T>
void work(int k, T cmp) {
  int A = set_y.size();
  tree_a.build(A, INF);
  tree_m.build(A, INF);
  for (int i = 1, j = 1; i <= n; ++i) {
    while (j <= m && cmp(fd[j].x, le[i].x)) {
      tree_a.modify(fd[j].y, -k * fd[j].x + set_y[fd[j].y - 1]);
      tree_m.modify(fd[j].y, -k * fd[j].x - set_y[fd[j].y - 1]);
      ++j;
    }
    update(ans[le[i].id], k * le[i].x - set_y[le[i].y - 1] + tree_a.query(le[i].y, A));
    update(ans[le[i].id], k * le[i].x + set_y[le[i].y - 1] + tree_m.query(1, le[i].y));
  }
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> le[i].x >> le[i].y;
    le[i].id = i;
    ans[i] = -1;
    set_y.emplace_back(le[i].y);
  }
  for (int i = 1; i <= m; ++i) {
    cin >> fd[i].x >> fd[i].y;
    fd[i].id = i;
    set_y.emplace_back(fd[i].y);
  }
  sort(set_y.begin(), set_y.end());
  set_y.erase(unique(set_y.begin(), set_y.end()), set_y.end());
  for (int i = 1; i <= n; ++i) {
    le[i].y = lower_bound(set_y.begin(), set_y.end(), le[i].y) - set_y.begin() + 1;
  }
  for (int i = 1; i <= m; ++i) {
    fd[i].y = lower_bound(set_y.begin(), set_y.end(), fd[i].y) - set_y.begin() + 1;
  }
  sort(le + 1, le + n + 1);
  sort(fd + 1, fd + m + 1);
  work(1, [](int x, int y) { return x <= y; });
  #ifdef DEBUG
  orzarr(ans + 1, n);
  #endif
  reverse(le + 1, le + n + 1);
  reverse(fd + 1, fd + m + 1);
  work(-1, [](int x, int y) { return x >= y; });
  #ifdef DEBUG
  orzarr(ans + 1, n);
  #endif
  ll sum = accumulate(ans + 1, ans + n + 1, 0ll);
  cout << sum << '\n';
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