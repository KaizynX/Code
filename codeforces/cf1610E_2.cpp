/*
 * @Author: Kaizyn
 * @Date: 2021-11-24 01:03:01
 * @LastEditTime: 2021-11-24 01:19:53
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
const int N = 2e5+7;

template <typename T>
struct Tree {
  struct Node {
    int l, r;
    T v;
  } tr[N<<1];
  void build(int n) { build(1, n, 1); }
  void build(int l, int r, int i) {
    tr[i].l = l; tr[i].r = r; tr[i].v = 0;
    if (l == r) return;
    int mid = (tr[i].l+tr[i].r)/2;
    bulid(l, mid, i<<1);
    build(mid+1, r, i<<1|1);
  }
  void update(int x, T v, int i = 1) {
    if (tr[i].l == tr[i].r) return tr[i].v = v, void();
    int mid = (tr[i].l+tr[i].r)/2;
    if (x <= mid) update(x, v, i<<1);
    else update(x, v, i<<1|1);
    tr[i].v = max(tr[i<<1].v, tr[i<<1|1].v);
  }
  void query(int l, int r, int i = 1) {
    if (tr[i].l >= l && tr[i].r <= r) return tr[i].v;
    int mid = (tr[i].l+tr[i].r)/2;
    if (r <= mid) return query(l, r, i<<1);
    if (l >  mid) return query(l, r, i<<1|1);
    return max(query(l, r, i<<1), query(l, r, i<<1|1));
  }
};

int n;
ll a[N], d[N];
Tree<ll> tree;
st<pair<ll, int>> st;

int getp() {
  ;
}

inline void solve() {
  cin >> n;
  tree.build(n);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i < n; ++i) {
    // printf("%9lld%c", 2*a[i]-a[i+1], " \n"[i==n-1]);
    d[i] =  2*a[i]-a[i+1];
    tree.update(i, d[i]);
    st.insert({d[i], i});
  }
  for (int i = 1; i < n; ++i) {
    ;
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
  }
  return 0;
}