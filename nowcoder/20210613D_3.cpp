/*
 * @Author: Kaizyn
 * @Date: 2021-06-13 17:32:47
 * @LastEditTime: 2021-06-13 17:36:40
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=610,INF=1e18;
int n,m,x,y,z,s,t,dis[MAXN][MAXN],w[MAXN],dap[MAXN],vis[MAXN],ord[MAXN];
int proc (int x) {
	memset(vis,0,sizeof(vis));
	memset(w,0,sizeof(w));
	w[0]=-1;
	for (int i=1;i<=n-x+1;i++) {
		int mx=0;
		for (int j=1;j<=n;j++) {
			if (!dap[j]&&!vis[j]&&w[j]>w[mx]) {mx=j;}
		}
		vis[mx]=1,ord[i]=mx;
		for (int j=1;j<=n;j++) {
			if (!dap[j]&&!vis[j]) {w[j]+=dis[mx][j];}
		}
	}
	s=ord[n-x],t=ord[n-x+1];
	return w[t];
}
int sw () {
	int res=INF;
	for (int i=1;i<n;i++) {
		res=min(res,proc(i));
		dap[t]=1;
		for (int j=1;j<=n;j++) {
			dis[s][j]+=dis[t][j];
			dis[j][s]+=dis[j][t];
		}
	}
	return res;
}
signed main () {
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> dis[i][j];
      sum += dis[i][j];
    }
  }
  cout << sum-2*sw() << '\n';
	return 0;
}