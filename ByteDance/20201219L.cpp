/*
 * @Author: Kaizyn
 * @Date: 2020-12-19 16:26:22
 * @LastEditTime: 2020-12-19 17:33:13
 */
//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=25; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)!=1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
int g[N][N],f[N][N],v[N],Max[N],n,ans;
vector<int> rec,maxrec;
bool dfs(int x,int cur){
	if(cur==0)
		return x>ans;
	repeat(i,0,cur){
		int u=f[x][i],k=0;
		if(Max[u]+x<=ans)return 0;
		repeat(j,i+1,cur)
		if(g[u][f[x][j]])
			f[x+1][k++]=f[x][j];
		rec.push_back(u);
		if(dfs(x+1,k))return 1;
		rec.pop_back();
	}
	return 0;
}
void solve(){
	ans=0; maxrec.clear();
	repeat_back(i,0,n){
		int k=0;
		repeat(j,i+1,n)
		if(g[i][j])
			f[1][k++]=j;
		rec.clear(); rec.push_back(i);
		if(dfs(1,k)){
			ans++;
			maxrec=rec;
		}
		Max[i]=ans;
	}
}
char s[N]; bool a[2000000][N];
int num[2000000];
int Ans[2000000];
bool vis[N];
vector<int> aans;
void Solve(){
	int n=read(),k=read();
	repeat(i,0,1<<n){
		scanf("%s",s);
		repeat(j,0,n+k)a[i][j]=s[j]-'0';
	}
	repeat(i,0,n+k)
	repeat(j,i+1,n+k){
		array<int,4> cnt={};
		repeat(t,0,1<<n){
			cnt[a[t][i]*2+a[t][j]]++;
		}
		if(*min_element(cnt.begin(),cnt.end())==(1<<(n-2)))
			g[i][j]=g[j][i]=1;
	}
	::n=n+k;
	solve();
	//orzeach(maxrec);
	if((int)maxrec.size()<n){
		puts("No");
		return;
	}
	repeat(i,0,1<<n){
		for(auto j:maxrec)
			num[i]=num[i]*2+(a[i][j]);
	}
	repeat(i,0,1<<n){
		Ans[num[i]]=i;
	}
	puts("Yes");
	repeat(i,0,1<<n)
		printf("%lld%c",Ans[i]+1," \n"[i+1==(1<<n)]);
	repeat(i,0,n)
		aans.push_back(maxrec[i]),vis[maxrec[i]]=1;
	repeat(i,0,n+k)if(!vis[i])aans.push_back(i);
	repeat(i,0,aans.size())
		printf("%lld%c",aans[i]+1," \n"[i+1==int(aans.size())]);
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}