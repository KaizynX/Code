/*
 * @Author: Kaizyn
 * @Date: 2021-08-26 13:45:19
 * @LastEditTime: 2021-08-26 15:03:11
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
const int N = 1e5+7;

struct TireTree {
  static const int SZ = 2;
  static const int B = 30;
  typedef array<int, SZ> T;
  vector<T> nex;
  TireTree() { init(); }
  void init() { nex.assign(1, T()); /* nex.reserve(N); */ }
  void clear() { nex = vector<T>(); }
  size_t size() const { return nex.size(); }
  void extend(int &x) {
    if (x != 0) return;
    x = nex.size();
    nex.emplace_back(T());
  }
  void insert(int x) {
    for (int i = B, c, p = 0; i >= 0; --i) {
      c = (x>>i)&1;
      extend(nex[p][c]);
      p = nex[p][c];
    }
  }
  int max_xor(int x) const {
    int ans = 0;
    for (int i = B, c, p = 0; i >= 0; --i) {
      c = (x>>i)&1;
      if (nex[p][c^1]) {
        p = nex[p][c^1];
        ans |= 1<<i;
      } else {
        p = nex[p][c];
      }
    }
    return ans;
  }
  void dfs(const TireTree &t, int p = 0, int pt = 0) {
    for (int c = 0; c < SZ; ++c) {
      if (t.nex[pt][c] == 0) continue;
      extend(nex[p][c]);
      dfs(t, nex[p][c], t.nex[pt][c]);
    }
  }
  void join(TireTree &t) {
    if (t.size() < size()) swap(*this, t);
    dfs(t);
    t.clear();
  }
};

int n, ans;
int a[N];
vector<pii> e[N];
list<int> nodes[N];
TireTree tree[N];

void dfs(int u, int fa = 0) {
  for (auto p : e[u]) {
    int v = p.first;
    if (v == fa) continue;
    a[v] = a[u]^p.second;
    dfs(v, u);
    if (nodes[u].size() < nodes[v].size()) {
      swap(nodes[u], nodes[v]);
      swap(tree[u], tree[v]);
    }
    for (int i : nodes[v]) {
      ans = max(ans, tree[u].max_xor(a[i]));
    }
    tree[u].join(tree[v]);
    nodes[u].splice(nodes[u].end(), nodes[v]);
  }
  ans = max(ans, tree[u].max_xor(a[u]));
  nodes[u].push_back(u);
  tree[u].insert(a[u]);
}


signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> n;
  for (int i = 1, u, v, w; i < n; ++i) {
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  dfs(1);
  cout << ans << '\n';
  return 0;
}