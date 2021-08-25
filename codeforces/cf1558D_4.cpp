/*
 * @Author: Kaizyn
 * @Date: 2021-08-25 14:26:52
 * @LastEditTime: 2021-08-25 14:30:37
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

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

struct Tree {
  struct Node {
    int l, r, v;
  } tr[N<<2];
  void push_up(int i) {
    tr[i].v = tr[i<<1].v+tr[i<<1|1].v;
  }
  void build(int l, int r, int i = 1) {
    tr[i].l = l; tr[i].r = r; tr[i].v = 0;
    if (l == r) return tr[i].v = 0, void();
    int mid = (l+r)>>1;
    build(l, mid, i<<1);
    build(mid+1, r, i<<1|1);
  }
  void add(int x, int k = 1, int i = 1) {
    if (tr[i].l == tr[i].r) return tr[i].v += k, void();
    int mid = (tr[i].l+tr[i].r)>>1;
    if (x <= mid) add(x, k, i<<1);
    else add(x, k, i<<1|1);
    push_up(i);
  }
  int query(int y, int i = 1) { // [1, x] == x-y
    if (tr[i].l == tr[i].r) return tr[i].l;
    int mid = (tr[i].l+tr[i].r)>>1;
    // if (y > mid || tr[i<<1].v+y > mid) return query(y+tr[i<<1].v, i<<1|1);
    if (tr[i<<1].v+y > mid) return query(y+tr[i<<1].v, i<<1|1);
    return query(y, i<<1);
  }
};

struct Combination {
  int fac[N<<1], inv[N<<1];
  Combination() {init(2*N-1); }
  void init(const int &n) {
    fac[0] = inv[0] = fac[1] = inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
      fac[i] = 1ll*fac[i-1]*i%MOD;
      inv[i] = 1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
    }
    for (int i = 2; i <= n; ++i) {
      inv[i] = 1ll*inv[i]*inv[i-1]%MOD;
    }
  }
  int A(const int &p, const int &q) {
    return p >= q ? 1ll*fac[p]*inv[p-q]%MOD : 0;
  }
  int C(const int &p, const int &q) {
    return p >= q ? 1ll*fac[p]*inv[q]%MOD*inv[p-q]%MOD : 0;
  }
};

int n, m;
int x[N], y[N], p[N], visp[N];
Combination comb;
Tree tree;

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> x[i] >> y[i];
  }
  int cnt = 0;
  for (int i = m; i; --i) {
    p[x[i]] = tree.query(y[i]);
    tree.add(p[x[i]]);
    visp[p[x[i]]] = 1;
    cnt += visp[p[x[i]]+1] == 0;
  }
  #ifdef DEBUG
  orz(cnt);
  #endif
  cout << comb.C(n+n-1-cnt, n) << '\n';
  for (int i = 1; i <= m; ++i) {
    tree.add(p[x[i]], -1);
    visp[p[x[i]]] = 0;
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  tree.build(1, N-1);
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
8 4
3 1
6 1
7 5
8 1

8 6
2 1
3 1
4 2
6 5
7 6
8 5

8 6
2 1
4 2
5 4
6 4
7 1
8 5

8 6
3 1
4 3
5 4
6 4
7 1
8 3

165
165
45
*/