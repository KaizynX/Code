/*
 * @Author: Kaizyn
 * @Date: 2021-11-24 16:30:41
 * @LastEditTime: 2021-11-24 16:32:10
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
// const int INF = 0x3f3f3f3f;
const ll INF = 1e12;
const ll inf = 1e12;
const int N = 5e4+7;
#define int ll

struct FLOW{
	struct edge{int to,w,nxt;};
	vector<edge> a; int head[N],cur[N];
	int n,s,t;
	queue<int> q; bool inque[N];
	int dep[N];
	void ae(int x,int y,int w){ // add edge
		a.push_back({y,w,head[x]});
		head[x]=a.size()-1;
	}
	bool bfs(){ // get dep[]
		fill(dep,dep+n,inf); dep[s]=0;
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
		return dep[t]!=inf;
	}
	int dfs(int x,int flow){ // extend
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
	int solve(int _s,int _t){ // return max flow
		s=_s,t=_t;
		int ans=0;
		while(bfs())ans+=dfs(s,inf);
		return ans;
	}
  void add_edge(int x,int y,int w){ae(x,y,w);ae(y,x,0);}
}flow;
// 先flow.init(n)，再add添边，最后flow.solve(s,t)

int n;
int w[N], v[N], d[N];
vector<int> e[N];
queue<int> q;

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> w[i];
  for (int i = 1; i <= n; ++i) cin >> v[i];
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].emplace_back(y);
    e[y].emplace_back(x);
  }
  int S = n*n+n+1, T = n*n+n+2;
  flow.init(T);
  ll ans = v[n]*n;
  for (int i = 1; i <= n; ++i) {
    flow.add_edge(n*n+i, T, w[i]);
    for (int j = 1, k; j <= n; ++j) {
      k = (i-1)*n+j;
      flow.add_edge(S, k, v[j]-v[j-1]);
      if (j > 1) flow.add_edge(k, k-1, INF);
      d[j] = 0;
    }
    d[i] = 1;
    q.push(i);
    while (q.size()) {
      int u = q.front();
      q.pop();
      flow.add_edge((i-1)*n+d[u], n*n+u, INF);
      for (int v : e[u]) if (!d[v]) {
        d[v] = d[u]+1;
        q.push(v);
      }
    }
  }
  ans -= flow.solve(S, T);
  cout << ans << '\n';
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