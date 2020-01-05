#include <bits/stdc++.h>
using namespace std;
using ll=long long; //using lll=__int128;
using pii=pair<int,int>;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define N 110
#define inf 1e9
#define qwq {cout<<"qwq"<<endl;}
#define quit {cout<<-1<<endl; exit(0);}
//#define int ll
const int mod=998244353;
int n,k;
int dp[N][N],a[N][N],vis[N][N];
struct node{int x,y;bool operator<(node b)const{return a[x][y]>a[b.x][b.y];}};
priority_queue<node> q;
const int dn[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while(cin>>n>>k,~n){
		repeat(i,0,n)
		repeat(j,0,n){
			cin>>a[i][j];
			dp[i][j]=0;
			vis[i][j]=0;
		}
		dp[0][0]=a[0][0];
		q.push((node){0,0});
		int ans=0;
		while(!q.empty()){
			int x=q.top().x,y=q.top().y; q.pop();
			if(vis[x][y])continue;
			vis[x][y]=1;
			ans=max(ans,dp[x][y]);
			repeat(i,0,4)
			repeat(j,1,k+1){
				int px=x+dn[i][0]*j,py=y+dn[i][1]*j;
				if(min(px,py)>=0 && max(px,py)<n)
				if(a[px][py]>a[x][y] && dp[x][y]+a[px][py]>dp[px][py]){
					q.push((node){px,py});
					dp[px][py]=dp[x][y]+a[px][py];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
