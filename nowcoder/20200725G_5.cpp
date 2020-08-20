/*
 * @Author: Kaizyn
 * @Date: 2020-08-05 20:57:30
 * @LastEditTime: 2020-08-07 16:25:30
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e4+7;
const int NN = (int)log2(N)+3;

struct FLOW{
	struct edge{int to,w,nxt;};
	vector<edge> a; int head[N],cur[N];
	int n,s,t;
	queue<int> q; bool inque[N];
	int dep[N];
	void ae(int x,int y,int w){ //add edge
		a.push_back({y,w,head[x]});
		head[x]=a.size()-1;
	}
  void clear() {
    for (int i = 0; i < (int)a.size(); i += 2) {
      a[i].w += a[i^1].w;
      a[i^1].w = 0;
    }
  }
  void modify_edge(const int &u, const int &v, const int &w) {
    for (int i = head[u]; ~i; i = a[i].nxt) if (a[i].to == v) {
      a[i].w = w;
      a[i^1].w = 0;
      break;
    }
  }
	bool bfs(){ //get dep[]
		fill(dep,dep+n,INF); dep[s]=0;
		copy(head,head+n,cur);
		q=queue<int>(); q.push(s);
		while(!q.empty()){
			int x=q.front(); q.pop(); inque[x]=0;
			for(int i=head[x];i!=-1;i=a[i].nxt){
				int p=a[i].to;
				if(dep[p]>dep[x]+1 && a[i].w){
					dep[p]=dep[x]+1;
					if(inque[p]==0){
						inque[p]=1;
						q.push(p);
					}
				}
			}
		}
		return dep[t]!=INF;
	}
	int dfs(int x,int flow){ //extend
		int now,ans=0;
		if(x==t)return flow;
		for(int &i=cur[x];i!=-1;i=a[i].nxt){
			int p=a[i].to;
			if(a[i].w && dep[p]==dep[x]+1)
			if((now=dfs(p,min(flow,a[i].w)))){
				a[i].w-=now;
				a[i^1].w+=now;
				ans+=now,flow-=now;
				if(flow==0)break;
			}
		}
		return ans;
	}
	void init(int _n){
		n=_n+1; a.clear();
		fill(head,head+n,-1);
		fill(inque,inque+n,0);
	}
	int work(int _s,int _t){ //return max flow
		s=_s,t=_t;
		int ans=0;
		while(bfs())ans+=dfs(s,INF);
		return ans;
	}
  void add_edge(int x,int y,int w){
    ae(x,y,w),ae(y,x,0);
  }
};
FLOW isap;

struct SegmentTreeGarph {
  struct TreeNode {
    int l, r, ls, rs;
    int len() const { return r-l+1; }
  } tr[N<<2];
  int tot, root[2];
  // op [down, 0] [up, 1]
  void build(const int &n) {
    tot = n;
    for (int i = 1; i <= n; ++i) tr[i].l = tr[i].r = i;
    // build(1, n, root[0], 0);
    build(1, n, root[1], 1);
  }
  void build(const int &l, const int &r, int &i, const int &op) {
    if (l == r) return i = l, void();
    i = ++tot;
    tr[i].l = l; tr[i].r = r;
    int mid = (l+r)>>1;
    build(l, mid, tr[i].ls, op);
    build(mid+1, r, tr[i].rs, op);
    isap.add_edge(op ? tr[i].ls : i, op ? i : tr[i].ls, INF);
    isap.add_edge(op ? tr[i].rs : i, op ? i : tr[i].rs, INF);
  }
  void insert(const int &o, int l, int r, const int &op = 1) {
    if (l > r) swap(l, r);
    insert(o, l, r, op, root[op]);
  }
  void insert(const int &o, const int &l, const int &r,
      const int &op, const int &i) {
    if (tr[i].l >= l && tr[i].r <= r) {
      isap.add_edge(op ? i : o, op ? o : i, INF);
      return;
    }
    int mid = (tr[i].l+tr[i].r)>>1;
    if (l <= mid) insert(o, l, r, op, tr[i].ls);
    if (r >  mid) insert(o, l, r, op, tr[i].rs);
  }
} stg;

struct HLD {
  int dfn;
  int fa[N], d[N], num[N], son[N], id[N], tp[N];
  vector<int> *e;
  template <typename E>
  void build(E *_e, const int &rt = 1) {
    e = _e;
    fa[rt] = dfn = 0;
    dfs1(rt);
    dfs2(rt);
  }
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
    id[u] = ++dfn;
    if (son[u]) dfs2(son[u]);
    for (const int &v : e[u]) if (v != son[u] && v != fa[u])
      dfs2(v);
  }
  int lca(int x, int y) {
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) swap(x, y);
      x = fa[tp[x]];
    }
    return d[x] < d[y] ? x : y;
  }
  void add_edge(int o, int x, int y) {
    if (d[x] < d[y]) swap(x, y); // x is son of y
    while (tp[x] != tp[y]) {
      isap.add_edge(id[x], o, INF);
      x = fa[tp[x]];
    }
    if (x != y) stg.insert(o, id[y]+1, id[x]);
  }
} hld;

int n, C, last_mid;
int c[N], vfa[N];
vector<int> e[N], ve[N], col[N];

// VirtualTree begin
void virtual_tree_clear(const int &u = 1) {
  for (const int &v : ve[u]) virtual_tree_clear(v);
  vfa[u] = 0;
  ve[u].clear();
}

// build a VirtualTree return the root
int virtual_tree_build(vector<int> &vset) {
  // id ==> dfn rank, d ==> depth
  static int stk[N], top;
  static int *id = hld.id, *d = hld.d;
  sort(vset.begin(), vset.end(), [&](const int &x, const int &y) {
    return id[x] < id[y];
  });
  top = 0;
  int x, z;
  for (const int &v : vset) {
    if (top && (z = hld.lca(v, stk[top])) != stk[top]) {
      x = stk[top--];
      while (top && d[stk[top]] > d[z]) {
        ve[stk[top]].emplace_back(x);
        vfa[x] = stk[top];
        x = stk[top--];
      }
      ve[z].emplace_back(x);
      vfa[x] = z;
      if (!top || stk[top] != z) stk[++top] = z;
    }
    stk[++top] = v;
  }
  x = stk[top--];
  while (top) {
    ve[stk[top]].emplace_back(x);
    vfa[x] = stk[top];
    x = stk[top--];
  }
  // if (x != 1) ve[1].emplace_back(x), vfa[x] = 1;
  return x;
}
// VirtualTree end

// (k*d) ==> 2*n+(k*d)
int build_stg(const int &u = 1) {
  int sum = c[u] == C;
  for (const int &v : ve[u])
    sum += build_stg(v);
  if (sum*C < n)
    hld.add_edge(2*n+sum*C, u, vfa[u]);
  return sum;
}

void build_network() {
  isap.init(n*3+2);
  stg.build(n);
  assert(stg.tot < n*2);
  for (C = 1; C <= n; ++C) if (col[C].size()) {
    int rt = virtual_tree_build(col[C]);
    build_stg(rt);
    virtual_tree_clear(rt);
  }
  int st = n*3+1, ed = n*3+2;
  isap.add_edge(2*n, ed, 1); // k*d == 0
  for (int i = 1; i <= n; ++i) {
    isap.add_edge(st, i, 1);
    isap.add_edge(i, 2*n, 1);
    isap.add_edge(2*n+i, ed, 1);
    if (hld.fa[i] && hld.tp[i] != i)
      isap.add_edge(hld.fa[i], i, INF);
  }
}

bool check(const int &mid) {
  int st = n*3+1, ed = n*3+2;
#ifdef DEBUG
  if (mid < last_mid) isap.clear();
  while (last_mid < mid) isap.modify_edge(2*n+(++last_mid), ed, 1);
  while (last_mid > mid) isap.modify_edge(2*n+(last_mid--), ed, 0);
#else
  isap.clear();
  for (int i = 0; i < n; ++i) {
    isap.modify_edge(2*n+i, ed, i <= mid);
  }
#endif
  return isap.work(st, ed) >= mid+1;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(NULL);

  cin >> n;
  for (int i = 2, p; i <= n; ++i) {
    cin >> p;
    e[p].emplace_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
    col[c[i]].emplace_back(i);
  }

  hld.build(e);
#ifdef DEBUG
  last_mid = n;
  build_network();
  cout << check(6) << endl; // 1
  cout << check(4) << endl; // 1
  cout << check(6) << endl; // 0 shit!
#endif
  int l = 0, r = n-1, mid;
  last_mid = n;
  build_network();
  while (l < r) {
    mid = (l+r+1)>>1;
    if (check(mid)) l = mid;
    else r = mid-1;
  }
  cout << l+1 << endl;
  return 0;
}