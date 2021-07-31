/*
 * @Author: Kaizyn
 * @Date: 2021-07-31 09:27:36
 * @LastEditTime: 2021-07-31 09:31:56
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e5+7;

struct DSU {
  vector<int> fa;
  void init(int n) { fa = vector<int>(n+1); iota(fa.begin(), fa.end(), 0); }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    return x == y ? false : (fa[x] = y, true);
  }
};
struct BIT{
	static const int SIZE=N;
	ll bit1[SIZE],bit2[SIZE];
	int limit;
	void init(int n=SIZE-1){
		limit=n;
		for(int i=1;i<=n;i++)bit1[i]=bit2[i]=0;
	}
	BIT(){init();}
	void add(ll *bit,int x,ll v){
		while(x<=limit)bit[x]+=v,x+=x&-x;
	}
	ll query(ll *bit,int x){
		ll res=0;
		while(x)res+=bit[x],x-=x&-x;
		return res;
	}
	void add(int x,ll v){ add(x,x,v);}
	void add(int l,int r,ll v){
		add(bit1,l,v);
		add(bit2,l,v*l);
		add(bit1,r+1,-v);
		add(bit2,r+1,-v*(r+1));
	}
	ll query(int x){ return query(x,x); }
	ll query(int l,int r){
		return (r+1)*query(bit1,r)-query(bit2,r)-l*query(bit1,l-1)+query(bit2,l-1);
	}
};

template <typename T>
struct HLD {
  int dfn;
  int fa[N], d[N], num[N], son[N], id[N], tp[N];
  vector<pii> *e;
  BIT t_xor, t_sum;
  void build(vector<pii> e[], const int &rt = 1) {
    this->e = e;
    fa[rt] = dfn = 0;
    dfs1(rt);
    dfs2(rt);
  }
  void dfs1(const int &u = 1) {
    // cout << u << '\n';
    d[u] = d[fa[u]]+1;
    num[u] = 1;
    son[u] = 0;
    for (auto p : e[u]) {
      int v = p.first;
      if (v == fa[u]) continue;
      fa[v] = u;
      dfs1(v);
      num[u] += num[v];
      if (num[v] > num[son[u]]) son[u] = v;
    }
  }
  void dfs2(const int &u = 1) {
    tp[u] = son[fa[u]] == u ? tp[fa[u]] : u;
    id[u] = ++dfn;
    if (son[u]) dfs2(son[u]);
    for (auto p : e[u]) {
      int v = p.first;
      int w = p.second;
      if (v == fa[u]) continue;
      if (v != son[u]) dfs2(v);
      t_xor.add(id[v], w);
    }
  }
  void add(int x, int y, const T &k, const int &is_edge = 1) {
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) swap(x, y);
      t_sum.add(id[tp[x]], id[x], k);
      x = fa[tp[x]];
    }
    if (d[x] > d[y]) swap(x, y);
    t_sum.add(id[x], id[y], k);
    if (is_edge) t_sum.add(id[x], -k);
  }
  T query(int x, int y, int is_edge = 1) {
    #ifdef DEBUG
    cout << "tree:query:" << x << ' ' << y << '\n';
    #endif
    T q_xor = 0, q_sum = 0;
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) swap(x, y);
      q_xor += t_xor.query(id[tp[x]], id[x]);
      q_sum += t_sum.query(id[tp[x]], id[x]);
      x = fa[tp[x]];
    }
    if (d[x] > d[y]) swap(x, y);
    q_xor += t_xor.query(id[x], id[y]);
    q_sum += t_sum.query(id[x], id[y]);
    if (is_edge) {
      q_xor -= t_xor.query(id[x]);
      q_sum -= t_sum.query(id[x]);
    }
    if (q_sum) return -1;
    return q_xor&1;
  }
};

int n, q;
int u[N], v[N], w[N], res[N];
vector<int> qset[N];
vector<pii> e[N];
DSU dsu;
HLD<int> tree;

void fuck(int i) {
  if (res[i] == -1) {
    int x = tree.query(u[i], v[i], 1);
    if (x == -1 || w[i] == x) res[i] = 0;
    else res[i] = 1, tree.add(u[i], v[i], 1, 1);
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> n >> q;
  dsu.init(n);
  for (int i = 1; i <= q; ++i) {
    cin >> u[i] >> v[i] >> w[i];
    res[i] = -1;
    if (dsu.merge(u[i], v[i])) {
      res[i] = 1;
      e[u[i]].emplace_back(v[i], w[i]);
      e[v[i]].emplace_back(u[i], w[i]);
    }
  }
  for (int i = 1; i <= q; ++i) {
    assert(dsu[u[i]] == dsu[v[i]]);
    qset[dsu[u[i]]].emplace_back(i);
  }
  tree.t_xor.init(n);
  tree.t_sum.init(n);
  for (int i = 1; i <= n; ++i) if (qset[i].size()) {
    tree.build(e, i);
    for (int j : qset[i]) fuck(j);
  }
  for (int i = 1; i <= q; ++i) {
    cout << (res[i] ? "YES" : "NO") << '\n';
  }
  return 0;
}