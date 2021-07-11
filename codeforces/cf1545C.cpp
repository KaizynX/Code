/*
 * @Author: Kaizyn
 * @Date: 2021-07-11 23:16:00
 * @LastEditTime: 2021-07-11 23:57:17
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
const int N = 1e3+7;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
void print(vector<int> &v) {
  for (int &i : v) cout << i << ' ';
  cout << '\n';
}
int g[N][N],n;
vector<int> rec, maxrec; //存当前极大团
int ans,some[N][N],none[N][N]; //some是未搜索的点，none是废除的点
void dfs(int d,int sn,int nn){
	if(sn==0 && nn==0) {
    if (rec.size() > maxrec.size()) {
      maxrec = rec;
      ans = 1;
    } else if (rec.size() == maxrec.size()) {
      print(rec);
      ++ans;
    }
  }
	//if(ans>1000)return; //题目要求_(:зゝ∠)_
	int u=some[d][0];
	for(int i=0;i<sn;++i){
		int v=some[d][i];
		if(g[u][v])continue;
		int tsn=0,tnn=0;
		for(int j=0;j<sn;++j)
		if(g[v][some[d][j]])
			some[d+1][tsn++]=some[d][j];
		for(int j=0;j<nn;++j)
		if(g[v][none[d][j]])
			none[d+1][tnn++]=none[d][j];
		rec.push_back(v);
		dfs(d+1,tsn,tnn);
		rec.pop_back();
		some[d][i]=0;
		none[d][nn++]=v;
	}
}
void hjt_solve(){ //运行后ans即极大团数
	ans=0;
  maxrec.clear();
	for(int i=0;i<n;++i)
		some[0][i]=i+1;
	dfs(0,n,0);
}
int a[N][N];
void solve(){
  cin >> n;
  for (int i = 1; i <= n*2; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
    g[i][i] = 0;
    for (int j = 1; j < i; ++j) {
      int flag = 1;
      for (int k = 1; k <= n; ++k) {
        flag &= a[i][k] != a[j][k];
      }
      g[i][j] = g[j][i] = flag;
    }
  }
  n *= 2;
  hjt_solve();
  cout << ans << '\n';
  print(maxrec);
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