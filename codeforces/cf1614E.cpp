/*
 * @Author: Kaizyn
 * @Date: 2021-11-27 23:27:22
 * @LastEditTime: 2021-11-28 00:05:01
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
const int MOD = 1e9+1;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

int n, m;
int T[N], p[N];
pii a[N];
vector<int> q[N];

struct SegmentTree {
  struct Node {
    int l, r;
    int minv, maxv, z;
    Node& operator += (const int &v) {
      minv += v;
      maxv += v;
      z += v;
      return *this;
    }
  } tr[N<<1];
  void push_up(int i) {
    tr[i].minv = min(tr[i<<1].minv, tr[i<<1|1].minv);
    tr[i].maxv = max(tr[i<<1].maxv, tr[i<<1|1].maxv);
  }
  void push_down(int i) {
    if (!tr[i].z) return;
    tr[i<<1] += tr[i].z;
    tr[i<<1|1] += tr[i].z;
    tr[i].z = 0;
  }
  void build(int n) { build(1, n, 1); }
  void build(int l, int r, int i) {
    tr[i].l = l; tr[i].r = r; tr[i].z = 0;
    if (l == r) return tr[i].minv = tr[i].maxv = a[l].first, void();
    int mid = (tr[i].l+tr[i].r)/2;
    build(l, mid, i<<1);
    build(mid+1, r, i<<1|1);
    push_up(i);
  }
  void add(int l, int r, int v, int i = 1) {
    if (tr[i].l >= l && tr[i].r <= r) return tr[i] += v, void();
    push_down(i);
    int mid = (tr[i].l+tr[i].r)/2;
    if (l <= mid) add(l, r, v, i<<1);
    if (r >  mid) add(l, r, v, i<<1|1);
    push_up(i);
  }
  int last_smaller(int v, int i = 1) {
    if (tr[i].l == tr[i].r) return tr[i].l-(tr[i].minv>=v);
    push_down(i);
    if (tr[i<<1|1].minv < v) return last_smaller(v, i<<1|1);
    else return last_smaller(v, i<<1);
  }
  int first_bigger(int v, int i = 1) {
    if (tr[i].l == tr[i].r) return tr[i].l+(tr[i].maxv<=v);
    push_down(i);
    if (tr[i<<1].maxv > v) return first_bigger(v, i<<1);
    else return first_bigger(v, i<<1|1);
  }
  int query(int x, int i = 1) {
    if (tr[i].l == tr[i].r) return tr[i].minv;
    push_down(i);
    int mid = (tr[i].l+tr[i].r)/2;
    if (x <= mid) return query(x, i<<1);
    else return query(x, i<<1|1);
  }
} tree;

inline void solve() {
  cin >> n;
  m = 0;
  for (int i = 1, k; i <= n; ++i) {
    cin >> T[i] >> k;
    q[i].resize(k);
    for (int j = 0, x; j < k; ++j) {
      cin >> x;
      q[i][j] = ++m;
      a[m] = {x, m};
    }
  }
  sort(a+1, a+m+1);
  for (int i = 1; i <= m; ++i) p[a[i].second] = i;
  #ifdef DEBUG
  orzarr(a+1, m);
  #endif
  tree.build(m);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int l = tree.last_smaller(T[i]);
    int r = tree.first_bigger(T[i]);
    #ifdef DEBUG
    cout << l << ' ' << r << "-\n";
    #endif
    if (1 <= l) tree.add(1, l, 1);
    if (r <= m) tree.add(r, m, -1);
    for (int j : q[i]) {
      ans = (ans+tree.query(p[j]))%MOD;
      cout << ans << '\n';
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