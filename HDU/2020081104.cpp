/*
 * @Author: Kaizyn
 * @Date: 2020-08-11 11:59:28
 * @LastEditTime: 2020-08-11 16:42:24
 */
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
//#define endl "\n"
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=1000010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
int a[N];
int fa[N][23],val[N][23];
#define log(x) (31-__builtin_clz(x))
int sum(int x,int len){
	int ans=0;
	while(len){
		ans+=val[x][log(len)];
		x=fa[x][log(len)];
		len-=1ll<<log(len);
	}
	return ans;
}
void Solve(){
	int t=read(),A=read(),C=read(); int n=(mod=read());
	repeat(i,0,n)fa[i][0]=(A*i+C)%mod,val[i][0]=i%2;
	repeat(j,1,23)
	repeat(i,0,n){
		fa[i][j]=fa[fa[i][j-1]][j-1];
		if(j==1)val[i][j]=val[i][j-1];
		else val[i][j]=val[i][j-1]+val[fa[i][j-1]][j-1];
	}
	ll ans=0;
	repeat(x0,0,2*t+1)
	if(x0%2==0){
		int len=min(x0,2*t-x0);
		if(len%2!=0)len--;
		ans+=sum(x0,len+1)*2-sum(x0,1);
	}
	else{
		int len=min(x0,2*t-x0);
		ans+=sum(fa[x0][0],len)*2;
	}
	printf("%lld\n",ans);
}
signed main(){
    //freopen("data.txt","r",stdin);
    int T=1; T=read();
    while(T--)Solve();
    return 0;
}