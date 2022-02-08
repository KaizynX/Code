/*
 * @Author: Kaizyn
 * @Date: 2022-02-07 16:20:53
 * @LastEditTime: 2022-02-07 16:37:52
 */
#include <bits/stdc++.h>

#define DEBUG

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

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e6 + 7;
const int A = 1e6;

template <typename T, typename U = greater<T>>
struct SegmentTree {
  U cmp = U();
  int n;
  T tr[N<<2];
  T mv(const T &x, const T &y) { return cmp(x, y) ? x : y;}
  void build(const int &_n, const T &k = 0) { n = _n; _build(1, n, k); }
  void modify(const int &x, const T &k) { _modify(x, k, 1, n); }
  T query(const int &x) { return _query(x, x, 1, n); }
  T query(const int &l, const int &r) { return _query(l, r, 1, n); }
private :
  void push_up(const int &i) { tr[i] = mv(tr[i<<1], tr[i<<1|1]); }
  void _build(const int &l, const int &r, const T &k = 0, const int &i = 1) {
    if (l == r) { tr[i] = k; return; }
    int mid = (l+r)>>1;
    _build(l, mid, k, i<<1);
    _build(mid+1, r, k, i<<1|1);
  }
  void _modify(const int &x, const T &k, const int &trl, const int &trr, const int &i = 1) {
    if (trl == x && trr == x) return tr[i] = k, void();
    int mid = (trl+trr)>>1;
    if (x <= mid) _modify(x, k, trl, mid, i<<1);
    else _modify(x, k, mid+1, trr, i<<1|1);
    push_up(i);
  }
  T _query(const int &l, const int &r, const int &trl, const int &trr, const int &i = 1) {
    if (trl >= l && trr <= r) return tr[i];
    int mid = (trl+trr)>>1;
    if (r <=  mid) return _query(l, r, trl, mid, i<<1);
    if (l >  mid) return _query(l, r, mid+1, trr, i<<1|1);
    return mv(_query(l, r, trl, mid, i<<1), _query(l, r, mid+1, trr, i<<1|1));
  }
};

int n;
multiset<int> st[N];
SegmentTree<int> tree;

inline void solve() {
  for (int i = 0; i <= A; ++i) st[i].insert(-INF);
  tree.build(A + 1, -INF);
  // cin >> n;
  scanf("%d", &n);
  for (int _ = n, op, a, b; _; --_) {
    // cin >> op >> a;
    scanf("%d%d", &op, &a);
    if (op == 1) {
      // cin >> b;
      scanf("%d", &b);
      st[a].insert(b);
      tree.modify(a + 1, *st[a].rbegin());
    } else if (op == 2) {
      // cin >> b;
      scanf("%d", &b);
      st[a].erase(st[a].find(b));
      tree.modify(a + 1, *st[a].rbegin());
    } else {
      int l = 0, r = A, mid;
      while (l < r) {
        mid = (l + r + 1) / 2;
        if (tree.query(mid + 1, A + 1) + a >= mid) l = mid;
        else r = mid - 1;
      }
      // cout << l << '\n';
      printf("%d\n", l);
    }
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