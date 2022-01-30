/*
 * @Author: Kaizyn
 * @Date: 2022-01-30 21:29:35
 * @LastEditTime: 2022-01-30 22:13:25
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
const int N = 2e5 + 7;

int n, q, X;
int a[N];

struct Tree {
  struct Node {
    int lazy;
    int cnt[3];
    void clear() {
      memset(cnt, 0, sizeof cnt);
    }
  } tr[N << 2];
  void push_up(int i) {
    for (int v : {0, 1, 2}) {
      tr[i].cnt[v] = tr[i << 1].cnt[v] + tr[i << 1 | 1].cnt[v];
    }
  }
  void push_down(int i, int len) {
    int &z = tr[i].lazy;
    if (z == -1) return;
    tr[i << 1].lazy = tr[i << 1 | 1].lazy = z;
    tr[i << 1].clear();
    tr[i << 1 | 1].clear();
    tr[i << 1].cnt[z] = (len + 1) / 2;
    tr[i << 1 | 1].cnt[z] = len / 2;
    z = -1;
  }
  void build(int l = 1, int r = n, int i = 1) {
    tr[i].clear();
    tr[i].lazy = -1;
    if (l == r) {
      tr[i].cnt[a[l]] = 1;
      return;
    }
    int mid = (l + r) / 2;
    build(l, mid, i << 1);
    build(mid + 1, r, i << 1 | 1);
    push_up(i);
  }
  void update(int L, int R, int v, int l = 1, int r = n, int i = 1) {
    if (L <= l && r <= R) {
      tr[i].lazy = v;
      tr[i].clear();
      tr[i].cnt[v] = r - l + 1;
      return;
    }
    push_down(i, r - l + 1);
    int mid = (l + r) / 2;
    if (L <= mid) update(L, R, v, l, mid, i << 1);
    if (R >  mid) update(L, R, v, mid + 1, r, i << 1 | 1);
    push_up(i);
  }
  pii query(int L, int R, int l = 1, int r = n, int i = 1) {
    if (L <= l && r <= R) return {tr[i].cnt[0], tr[i].cnt[1]};
    push_down(i, r - l + 1);
    int mid = (l + r) / 2;
    if (R <= mid) return query(L, R, l, mid, i << 1);
    if (L >  mid) return query(L, R, mid + 1, r, i << 1 | 1);
    pii lhs = query(L, R, l, mid, i << 1);
    pii rhs = query(L, R, mid + 1, r, i << 1 | 1);
    return {lhs.first + rhs.first, lhs.second + rhs.second};
  }
} tree;

#ifdef DEBUG
void print() {
  for (int i = 1; i <= n; ++i) {
    pii qry = tree.query(i, i);
    if (qry.first) cout << 0 << ' ';
    else if (qry.second) cout << 1 << ' ';
    else cout << 2 << ' ';
  }
  cout << '\n';
}
#endif

inline void solve() {
  cin >> n >> q >> X;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] < X) a[i] = 0;
    else if (a[i] > X) a[i] = 1;
    else a[i] = 2;
  }
  tree.build();
  #ifdef DEBUG
  print();
  #endif
  for (int _ = q, c, l, r; _; --_) {
    cin >> c >> l >> r;
    pii qry = tree.query(l, r);
    int t0 = qry.first, t1 = qry.second;
    #ifdef DEBUG
    orz(t0);
    orz(t1);
    #endif
    if (c == 1) {
      tree.update(l, l + t0 - 1, 0);
      tree.update(r - t1 + 1, r, 1);
      if (t0 + t1 < r - l + 1) tree.update(l + t0, r - t1, 2);
    } else {
      tree.update(l, l + t1 - 1, 1);
      tree.update(r - t0 + 1, r, 0);
      if (t0 + t1 < r - l + 1) tree.update(l + t1, r - t0, 2);
    }
    #ifdef DEBUG
    print();
    #endif
  }
  for (int i = 1; i <= n; ++i) {
    pii qry = tree.query(i, i);
    if (qry.first == 0 && qry.second == 0) {
      cout << i << '\n';
      break;
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
/*
7 3 3
7 5 3 1 2 4 6
1 1 7
2 3 6
2 5 7

1 1 2 0 0 1 1
0 0 2 1 1 1 1
0 0 1 1 1 1 2
0 0 1 1 1 1 2

*/