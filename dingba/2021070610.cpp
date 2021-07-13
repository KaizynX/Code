/*
 * @Author: Kaizyn
 * @Date: 2021-07-13 12:50:37
 * @LastEditTime: 2021-07-13 17:35:07
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

template <typename T>
struct Heap{
  priority_queue<T> a,b;  // heap=a-b
  void push(T x){a.push(x);}
  void erase(T x){b.push(x);}
  T top(){
    while(!b.empty() && a.top()==b.top())
      a.pop(),b.pop();
    return a.size() ? a.top() : 0;
  }
  void pop(){
    while(!b.empty() && a.top()==b.top())
      a.pop(),b.pop();
    a.pop();
  }
  T top2(){ // 次大值
    T t=top(); pop();
    T ans=top(); push(t);
    return ans;
  }
  size_t size(){return a.size()-b.size();}
};

namespace DT {

int *a, n, dfn;
// id[i] 点i的dfs序
// rid[i] dfs序为i的结点编号
// tail[i] i所在重链的最深结点
int fa[N], d[N], num[N], son[N], id[N], rid[N], tp[N], tail[N];
// g[i] = sum{f[j]}(j是i的轻儿子)
// f[i] = max{0, f[son[i]]+g[i]} 选择i时的最大联通子块和
// ms[i] i的子树中的最大连通子块和
ll g[N], f[N], ms[N];
vector<int> *e;
// mx[i] 维护i中轻儿子ms的最大值
Heap<ll> mx[N];
struct TreeNode {
  long long s, ls, rs, ms;
  // void set(ll x) { s = ls = rs = ms = x; }
  void set(int x) {
    x = rid[x];
    s = g[x];
    ls = rs = max(g[x], 0ll);
    // 重链上信息即为最大区间和, (轻链及子树信息)将mx[]信息在此处维护
    ms = max(g[x], mx[x].top());
  }
  friend TreeNode operator +(const TreeNode &lc, const TreeNode &rc) {
    return TreeNode {
        lc.s+rc.s,
        max(lc.ls, lc.s+rc.ls),
        max(rc.rs, lc.rs+rc.s),
        max({lc.ms, rc.ms, lc.rs+rc.ls})
    };
  }
} tr[N<<2];

void build(int l, int r, int i) {
  if (l == r) return tr[i].set(l);
  int mid = (l+r)>>1;
  build(l, mid, i<<1);
  build(mid+1, r, i<<1|1);
  tr[i] = tr[i<<1]+tr[i<<1|1];
}
void update(int x, int l, int r, int i) {
  if (l == r) return tr[i].set(l);
  int mid = (l+r)>>1;
  if (x <= mid) update(x, l, mid, i<<1);
  else update(x, mid+1, r, i<<1|1);
  tr[i] = tr[i<<1]+tr[i<<1|1];
}
void update(int x) { update(x, 1, n, 1); }
TreeNode query(int L, int R, int l, int r, int i) {
  if (l >= L && r <= R) return tr[i];
  int mid = (l+r)>>1;
  if (R <= mid) return query(L, R, l, mid, i<<1);
  if (L >  mid) return query(L, R, mid+1, r, i<<1|1);
  return query(L, R, l, mid, i<<1)+query(L, R, mid+1, r, i<<1|1);
}
TreeNode query(int L, int R) { return query(L, R, 1, n, 1); }

void dfs1(const int &u = 1) {
  d[u] = d[fa[u]]+1;
  num[u] = 1;
  son[u] = 0;
  for (const int &v : e[u]) if (v != fa[u]) {
    fa[v] = u;
    dfs1(v);
    num[u] += num[v];
    if (num[v] > num[son[u]]) son[u] = v;
  }
}
void dfs2(const int &u = 1) {
  tp[u] = son[fa[u]] == u ? tp[fa[u]] : u;
  id[u] = ++dfn; rid[dfn] = u;
  tail[u] = u;
  g[u] = a[u];
  if (son[u]) {
    dfs2(son[u]);
    tail[u] = tail[son[u]];
    ms[u] = ms[son[u]];
  }
  for (const int &v : e[u]) if (v != son[u] && v != fa[u]) {
    dfs2(v);
    g[u] += f[v];
    mx[u].push(ms[v]);
  }
  f[u] = max(0ll, g[u]+f[son[u]]);
  ms[u] = max({ms[u], f[u], mx[u].top()});
}
void Build(vector<int> *e, int *a, int n, int rt = 1) {
  DT::e = e;
  DT::a = a;
  DT::n = n;
  fa[rt] = dfn = 0;
  dfs1(rt);
  dfs2(rt);
  build(1, n, 1);
}
void Update(int x, int v) {
  TreeNode t1, t2; // 记录上一次跳转信息
  ll y = v-a[x]; // y记录g[]变化差值
  a[x] = v;
  for (int flag = 0; x; x = fa[tp[x]], flag = 1) {
    if (flag) mx[x].erase(t1.ms), mx[x].push(t2.ms);
    t1 = query(id[tp[x]], id[tail[tp[x]]]);
    g[x] += y;
    update(id[x]);
    t2 = query(id[tp[x]], id[tail[tp[x]]]);
    y = t2.ls-f[tp[x]];
    f[tp[x]] = t2.ls;
  }
}
ll Query(int x) {
  return query(id[x], id[tail[x]]).ms;
}

} // namespace


int n, m;
int a[N];
vector<int> e[N];

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  DT::Build(e, a, n);
  for (int _ = m, x, y; _; --_) {
    char op;
    cin >> op >> x;
    if (op == 'M') {
      cin >> y;
      DT::Update(x, y);
    } else {
      cout << DT::Query(x) << '\n';
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