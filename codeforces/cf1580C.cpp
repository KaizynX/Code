/*
 * @Author: Kaizyn
 * @Date: 2021-09-30 18:05:15
 * @LastEditTime: 2021-09-30 19:40:06
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
const int B = 301;

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

int n, m;
int x[N], y[N], z[N], k[N], add[N], vis[N];
BinaryIndexedTree<int> tree[B];

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i];
    z[i] = x[i]+y[i];
  }
  int cur = 0;
  for (int i = 1; i < B; ++i) tree[i].init(B);
  for (int i = 1, op, k, val; i <= m; ++i) {
    cin >> op >> k;
    cur += add[i];
    val = op == 1 ? 1 : -1;
    if (z[k] >= B) {
      if (op == 1) vis[k] = i;
      for (int j = vis[k]; j <= m; j += z[k]) {
        if (j+x[k] <= m) add[j+x[k]] += val;
        if (j+z[k] <= m) add[j+z[k]] -= val;
        if (i >= j+x[k] && i < j+z[k]) cur += val;
      }
    } else {
      int l = (i+x[k])%z[k], r = i%z[k]; // [l, r) l != r
      auto &tr = tree[z[k]];
      if (l < r) {
        tr.add(l+1, r, val);
        if (1 <= l) tr.add(1, l, -val);
        tr.add(r+1, z[k]+1, -val);
      } else {
        tr.add(l+1, z[k]+1, val);
        if (1 <= r) tr.add(1, r, val);
        tr.add(r+1, l, val);
      }
    }
    int ans = cur;
    for (int j = 2; j < B; ++j) {
      ans += tree[j].query(i%j+1);
    }
    cout << ans << '\n';
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