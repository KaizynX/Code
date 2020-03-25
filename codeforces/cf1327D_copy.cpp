/*
 * @Author: Kaizyn
 * @Date: 2020-03-24 08:35:34
 * @LastEditTime: 2020-03-24 08:36:06
 */
#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
#ifndef qwq
int cansel_sync=[]{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
#endif
const double err=1e-11; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<int,int> pii; template<typename A,typename B> ostream &operator<<(ostream &o,const pair<A,B> &x){return o<<'('<<x.fi<<','<<x.se<<')';}
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=200010;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
#define int ll
int t,n,m,ans;
int a[N],co[N],vis[N];
vector<int> rec,v;
bool work2(int s,int step){
	int n=rec.size();
	int p=s,nxt=(p+step)%n;
	while(nxt!=s){
		if(rec[p]!=rec[nxt])return 0;
		p=nxt,nxt=(p+step)%n;
	}
	return 1;
}
void work(){
	//orzeach(rec);
	int n=rec.size();
	for(int i=1;i<n;i=n/(n/(i+1)))
	if(n%i==0){
		repeat(j,0,i){
			if(ans<=i)return;
			if(work2(j,i)){
				ans=min(ans,i);
				return;
			}
		}
	}
	int i=n;
	repeat(j,0,i){
		if(ans<=i)return;
		if(work2(j,i)){
			ans=min(ans,i);
			return;
		}
	}
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		fill(vis,vis+n+1,0);
		repeat(i,1,n+1)cin>>a[i];
		repeat(i,1,n+1)cin>>co[i];
		ans=inf;
		repeat(i,1,n+1)if(!vis[i]){
			int p=i;
			rec.clear();
			while(!vis[p]){
				rec.push_back(co[p]);
				vis[p]=co[p];
				p=a[p];
			}
			work();
		}
		cout<<ans<<endl;
	}
	return 0;
}