// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#define repeat(i,a,b) for(int i=(a),ib=(b);i<ib;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,ib=(a);i>=ib;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
#define int ll
using namespace std;
namespace start{
	typedef long long ll; const int inf=INT_MAX>>1; const ll INF=INT64_MAX>>1;
	typedef double lf; const lf pi=acos(-1.0);
	typedef pair<int,int> pii;
	mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
		ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;} // will detect EOF
		ll readfast(){
			ll x=0,tag=1; char c=getchar(); for(;!isdigit(c);c=getchar())if(c=='-')tag=-1;
			for(;isdigit(c);c=getchar())x=x*10+c-48; // ungetc(c,stdin);
			return x*tag;
		}
		template<typename T> void write(T x){
			if(x<0)x=-x,putchar('-');
			if(x>=10)write(x/10);
			putchar(x%10+48);
		}
		void print(ll x,bool e=0){printf("%lld%c",x," \n"[e]);}
		lf readf(){lf x; if(scanf("%lf",&x)!=1)exit(0); return x;} // will detect EOF
		void printlf(lf x,bool e=0){printf("%.12f%c",x," \n"[e]);}
		template<typename T> vector<T> &operator<<(vector<T> &a,const T &b){a.push_back(b); return a;}
		template<typename T> T sqr(const T &x){return x*x;}
		// int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
		constexpr int bitlog(ll x){return 63-__builtin_clzll(x);} // floor(log2(x))
	const int N=100010;
	const lf eps=1e-9;
	const int mod=(0?1000000007:998244353);
		int mul(int a,int b,int m=mod){return 1ll*a*b%m;}
		int qpow(int a,ll b,int m=mod){int ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
}using namespace start;
bool vis[N]; int lpf[N]; vector<int> a;
void get_prime(){
	vis[1]=1;
	repeat(i,2,N){
		if(!vis[i])a.push_back(i),lpf[i]=i;
		for(auto j:a){
			if(i*j>=N)break;
			vis[i*j]=1; lpf[i*j]=j;
			if(i%j==0)break;
		}
	}
}
vector<pii> pd; vector<ll> divisor;
void dfs(int x,int y,ll s){
	if(x==(int)pd.size()){divisor.push_back(s); return;}
	dfs(x+1,0,s);
	if(y<pd[x].se)dfs(x,y+1,s*pd[x].fi);
}
void get_divisor(ll n){
	pd.clear(); divisor.clear();
	while(n!=1){
		if(!pd.empty() && pd.back().fi==lpf[n])pd.back().se++;
		else pd.push_back({lpf[n],1});
		n/=lpf[n]; // needs initialized
	}
	dfs(0,0,1);
	sort(divisor.begin(),divisor.end());
}
int inv26=qpow(26,mod-2);
int p26[N],patial[N];
int inter(const array<int,3> &a,const array<int,3> &b){
	return !(a[1]<b[0] || b[1]<a[0]);
}
int query(const array<int,3> &a,const array<int,3> &b){
	if(!inter(a,b))return 0;
	return (min(a[1],b[1])-max(a[0],b[0])+1)*a[2]%mod*b[2]%mod;
}
void getv(int n,vector<array<int,3>> &v){
	get_divisor(n);
//	orz(n,divisor);
//	for(auto i:divisor)orz(i,patial[i]);
	int inv=qpow(26,n*(mod-2));
	v.push_back({1,1,patial[1]*inv%mod});
	repeat(i,1,divisor.size()){
		v.push_back({divisor[i-1]+1,divisor[i],patial[divisor[i]]*inv%mod});
	}
	repeat_back(i,0,v.size()-1)(v[i][2]+=v[i+1][2])%=mod;
}
vector<array<int,3>> v1,v2;
void Solve(){
	int n=read(); ll ans=0;
	repeat(i,0,n)a[i]=read();
	if(n==1){puts("1"); return;}
	getv(a[0],v1);
	repeat(i,0,n){
		getv(a[(i+1)%n],v2);
		unsigned p=0;
		repeat(i,0,v1.size()){
			if(p<v2.size())(ans+=query(v1[i],v2[p]))%=mod;
			while(p<v2.size() && v2[p][1]<=v1[i][1]){
				p++;
				if(p<v2.size())(ans+=query(v1[i],v2[p]))%=mod;
			}
		}
		v1=move(v2);
	}
	print(ans);
}
signed main(){
//	orz(qpow(26,6));
	p26[0]=1; repeat(i,1,N)p26[i]=p26[i-1]*26%mod;
	get_prime();
	repeat(i,1,N){
		(patial[i]+=p26[i])%=mod;
		for(int j=i+i;j<N;j+=i){
			(patial[j]+=mod-patial[i])%=mod;
		}
	}
	repeat(i,1,N)patial[i]=patial[i]*qpow(i,mod-2)%mod;
	// freopen("data.txt","r",stdin);
	int T=1; // T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}
