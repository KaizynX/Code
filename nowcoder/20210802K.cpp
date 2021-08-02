/*
 * @Author: Kaizyn
 * @Date: 2021-08-02 16:12:13
 * @LastEditTime: 2021-08-02 16:52:16
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
constexpr int P=998244353;
const int N = 5e5+7;

struct Rand{
    unsigned int n,seed;
    Rand(unsigned int n,unsigned int seed)
    :n(n),seed(seed){}
    int get(long long lastans){
        seed ^= seed << 13;
        seed ^= seed >> 17;
        seed ^= seed << 5;
        return (seed^lastans)%n+1;
    }
};
int n, m, seed;
int a[N];
vector<int> e[N];
struct Node {
	ll val[2][2];
	Node(ll x) {
		val[0][0] = val[0][1] = val[1][0] = 0;
		val[1][1] = x;
	}
	Node operator +(const Node &b) const {
		Node res(0);
		for (int i : {0, 1}) for (int j : {0, 1}) {
			res.val[i][j] = max({
					val[i][0]+b.val[0][j],
					val[i][0]+b.val[1][j],
					val[i][1]+b.val[0][j]
			});
		}
		return res;
	}
  Node rev() {
    Node res=*this;
    swap(res.val[0][1], res.val[1][0]);
    return res;
  }
	void print() {
		cout << "(" << val[0][0] << ' ' << val[0][1] << ' ' << val[1][0] << ' ' << val[1][1] << ") ";
	}
};
struct cat{
  #define repeat(i, a, b) for (int i = (a), ib = (b); i < ib; i++)
#define repeat_back(i, a, b) for (int i = (b) - 1, ib = (a);i >= ib; i--)

	#define U(a,b) (a + b)
	#define logN 21
	vector<Node> a[logN];
	vector<Node> v;
	void init(){
		repeat(i,0,logN)a[i].clear();
		v.clear();
	}
	void push(ll in){
		v.push_back(Node(in));
		int n=v.size()-1;
		repeat(s,1,logN){
			int len=1<<s; int l=n/len*len;
			if(n%len==len/2-1){
				repeat(i,0,len)a[s].push_back(Node(0));
				a[s][l + len / 2 - 1] = v[l + len / 2 - 1];
				repeat_back(i,0,len/2 - 1)a[s][l+i]=U(v[l+i],a[s][l+i+1]);
			}
			if(n%len==len/2)
				a[s][n]=v[n];
			if(n%len>len/2)
				a[s][n]=U(a[s][n-1],v[n]);
		}
	}
	Node query(int l,int r){  l--, r--;
    // if (l>r)return Node(0);
		if(l==r)return v[l];
		int s=__lg(l^r)+1;
		return U(a[s][l],a[s][r]);
	}
}tr;
struct HLD {
  int dfn;
  int fa[N], d[N], num[N], son[N], id[N], tp[N];
  int init_val[N];
  void build(int rt = 1) {
    fa[rt] = dfn = 0;
    dfs1(rt);
    dfs2(rt);
    for (int i = 1; i <= n; ++i) {
      init_val[id[i]] = a[i];
    }
    for (int i = 1; i <= n; ++i) {
      tr.push(init_val[i]);
    }
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
  Node query(int x, int y) {
    Node resx(0),resy(0);
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) {
        resy = tr.query(id[tp[y]], id[y])+resy;
        y = fa[tp[y]];
      } else {
        resx = resx+tr.query(id[tp[x]], id[x]).rev();
        x = fa[tp[x]];
      }
    }
    if (d[x] > d[y]) {
      resy = tr.query(id[y], id[x])+resy;
    } else {
      resx = resx+tr.query(id[x], id[y]).rev();
    }
    return resx+resy;
  }
} hld;

inline ll query(int u, int v) {
  Node res = hld.query(u, v);
  return max({res.val[0][0], res.val[0][1], res.val[1][0], res.val[1][1]});
}

signed main() {
  scanf("%d%d%d",&n,&m,&seed);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  for (int i = 2,f; i <= n; ++i) {
    scanf("%d", &f);
    e[f].emplace_back(i);
  }
  hld.build();
  Rand rand(n,seed);
  long long lastans=0,ans=0;
  for(int i=0;i<m;i++){
    int u=rand.get(lastans);
    int v=rand.get(lastans);
    int x=rand.get(lastans);
    lastans=query(u,v);//calculate the answer
    ans=(ans+lastans%P*x)%P;
  }
  printf("%lld\n",ans);
  return 0;
}