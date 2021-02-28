// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
// int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)!=1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> vector<T> &operator<<(vector<T> &a,T b){a.push_back(b); return a;} template<typename T> T sqr(T x){return x*x;} void print(ll x,bool e=0){printf("%lld%c",x," \n"[e]);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
// #define int ll
#define U(x,y) ((x)+(y))
#define U0 0
struct kdt{
	struct range{
		int l,r;
		range operator|(range b)const{
			return {min(l,b.l),max(r,b.r)};
		}
		bool out(range b){
			return l>b.r || b.l>r;
		}
		bool in(range b){
			return b.l<=l && r<=b.r;
		}
	};
	struct node{
		int x,y,a; // (x,y): coordinate, a: value
		int s,d,sz; // s: sum of value in subtree, d: cut direction, sz: size of subtree
		range xx,yy; // xx/yy: range of coordinate x/y
		node *l,*r; // left/right child
		void up(){
			sz=l->sz+r->sz+1;
			s=U(a,U(l->s,r->s));
			xx=range{x,x} | l->xx | r->xx;
			yy=range{y,y} | l->yy | r->yy;
		}
		node *&ch(int px,int py){ // in which child
			if(d==0)return px<x ? l : r;
			else return py<y ? l : r;
		}
		node(){
			sz=0; a=s=U0;
			xx=yy={inf,-inf};
			l=r=Null;
		}
		node(int x_,int y_,int a_){
			x=x_,y=y_,a=a_;
			l=r=Null;
			up();
		}
	}*rt;
	static node Null[N],*pl;
	vector<node *> cache;
	void init(){ // while using kdtrees, notice Null is static
		rt=pl=Null;
	}
	node *build(node **l,node **r,int d){ // private
		if(l>=r)return Null;
		node **mid=l+(r-l)/2;
		if(d==0)
			nth_element(l,mid,r,[&](node *a,node *b){
				return a->x < b->x;
			});
		else
			nth_element(l,mid,r,[&](node *a,node *b){
				return a->y < b->y;
			});
		node *u=*mid;
		u->d=d;
		u->l=build(l,mid,d^1);
		u->r=build(mid+1,r,d^1);
		u->up();
		return u;
	}
	void pia(node *u){ // private
		if(u==Null)return;
		pia(u->l);
		cache.push_back(u);
		pia(u->r);
	}
	void insert(node *&u,int x,int y,int v){ // private
		if(u==Null){
			*++pl=node(x,y,v); u=pl; u->d=0;
			return;
		}
		insert(u->ch(x,y),x,y,v);
		u->up();
		if(0.725*u->sz <= max(u->l->sz,u->r->sz)){
			cache.clear();
			pia(u);
			u=build(cache.data(),cache.data()+cache.size(),u->d);
		}
	}
	void insert(int x,int y,int v){
		insert(rt,x,y,v);
	}
	range qx,qy;
	int query(node *u){ // private
		if(u==Null)return U0;
		if(u->xx.out(qx) || u->yy.out(qy))return U0;
		if(u->xx.in(qx) && u->yy.in(qy))return u->s;
		return U((range{u->x,u->x}.in(qx) && range{u->y,u->y}.in(qy) ? u->a : U0),
			U(query(u->l),query(u->r)));
	}
	int query(int x1,int y1,int x2,int y2){
		qx={x1,x2};
		qy={y1,y2};
		return query(rt);
	}
}tr;
kdt::node kdt::Null[N],*kdt::pl;
void Solve(){
	tr.init();
	int n,op,lastans=0,xl,yl,xr,yr;
	scanf("%d",&n);
	while(~scanf("%d",&op)){
		if(op==1){
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			x^=lastans;
			y^=lastans;
			v^=lastans;
			tr.insert(x,y,v);
		}
		if(op==2){
			scanf("%d%d%d%d",&xl,&yl,&xr,&yr);
			xl^=lastans;
			yl^=lastans;
			xr^=lastans;
			yr^=lastans;
			if(xl>xr)swap(xl,xr);
			if(yl>yr)swap(yl,yr);
			printf("%d\n",lastans=tr.query(xl,yl,xr,yr));
		}
		if(op==3)return;
	}
}
signed main(){
	// freopen("data.txt","r",stdin);
	int T=1; // T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}