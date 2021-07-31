/*
 * @Author: Kaizyn
 * @Date: 2021-07-31 12:29:57
 * @LastEditTime: 2021-07-31 12:41:26
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
const int N = 6e2+7;

int e[N][N],n,m; // 邻接矩阵，左顶点数，右顶点数
int lx[N],ly[N]; // 顶标
int mch[N]; // 右顶点i连接的左顶点编号
bool fx[N],fy[N]; // 是否在增广路上
bool dfs(int i){
	fx[i]=1;
	repeat(j,0,n)
	if(lx[i]+ly[j]==e[i][j] && !fy[j]){
		fy[j]=1;
		if(mch[j]==-1 || dfs(mch[j])){
			mch[j]=i;
			return 1;
		}
	}
	return 0;
}
void update(){
	int fl=inf;
	repeat(i,0,n)if(fx[i])
	repeat(j,0,m)if(!fy[j])
		fl=min(fl,lx[i]+ly[j]-e[i][j]);
	repeat(i,0,n)if(fx[i])lx[i]-=fl;
	repeat(j,0,m)if(fy[j])ly[j]+=fl;
}
int solve(){ // 返回匹配数
	repeat(i,0,n){
		mch[i]=-1;
		lx[i]=ly[i]=0;
		repeat(j,0,m)
			lx[i]=max(lx[i],e[i][j]);
	}
	repeat(i,0,n)
	while(1){
		repeat(j,0,m)
			fx[j]=fy[j]=0;
		if(dfs(i))break;
		else update();
	}
	int ans=0;
	repeat(i,0,m)
	if(mch[i]!=-1)
		ans+=e[mch[i]][i];
	return ans;
}

int n;
int x[N], y[N], z[N], v[N];
ZKW_SPFA<ll> flow;

ll d(int i, int t) {
  return x[i]*x[i]+y[i]*y[i]+1ll*(z[i]+t*v[i])*(z[i]+t*v[i]);
}

inline void solve() {
  cin >> n;
  int S = 2*n+1, T = 2*n+2;
  flow.init(2*n+2);
  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i] >> z[i] >> v[i];
    flow.add_edge(S, i, 1, 0);
    flow.add_edge(n+i, T, 1, 0);
    for (int t = 0; t < n; ++t) {
      flow.add_edge(t+1, n+i, 1, d(i, t));
      
    }
  }
  cout << flow.work(S, T).second << '\n';
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