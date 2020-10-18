/*
 * @Author: Kaizyn
 * @Date: 2020-09-30 20:19:22
 * @LastEditTime: 2020-09-30 20:35:18
 */
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ch() getchar()
#define pc(x) putchar(x)
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define qwq [&]{cerr<<"qwq"<<endl;}()
#define orz(x) [&]{cerr<<#x": "<<x<<endl;}()
#define orzarr(a,n) [&]{cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}()
#define orzeach(a) [&]{cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}()
#define pause [&]{system("pause");}()
template<typename T>inline void read(T&x){
	int f;char c;
	for(f=1,c=ch();c<'0'||c>'9';c=ch())if(c=='-')f=-f;
	for(x=0;c<='9'&&c>='0';c=ch())x=x*10+(c&15);x*=f;
}
template<typename T>inline void write(T x){
	static char q[64];int cnt=0;
	if(!x)pc('0');if(x<0)pc('-'),x=-x;
	while(x)q[cnt++]=x%10+'0',x/=10;
	while(cnt--)pc(q[cnt]);
}
const int maxn=50005,mod=998244353;
int mo(const int x){
	return x>=mod?x-mod:x;
}
int power(int a,int x){
	int re=1;
	while(x){
		if(x&1)re=1ll*re*a%mod;
		a=1ll*a*a%mod,x>>=1;
	}
	return re;
}
int rev[maxn*4],N;
void NTT(int*F,int rv){
	for(int i=0;i<N;++i)if(rev[i]<i)
		F[rev[i]]^=F[i]^=F[rev[i]]^=F[i];
	for(int mid=1;mid<N;mid<<=1){
		int len=mid<<1,gn=power(3,(mod-1)/len);
		for(int i=0;i<N;i+=len){
			for(int j=0,g=1;j<mid;++j,g=1ll*g*gn%mod){
				int l=i+j,r=l+mid;
				int L=F[l],R=1ll*F[r]*g%mod;
				F[l]=mo(L+R),F[r]=mo(mod-R+L);
			}
		}
	}
	if(!rv)return;reverse(F+1,F+N);int tmp=power(N,mod-2);
	for(int i=0;i<N;++i)F[i]=1ll*tmp*F[i]%mod;
}
int F[maxn*4],G[maxn*4],S[maxn*2],L[maxn*2],R[maxn*2];
void solve(int l,int r){
	if(l==r)return;int mid=(l+r)>>1,o=mid+1;
	solve(l,mid);solve(o,r);
	int mx=R[l]-L[l]+R[o]-L[o]-1,cn=-1;N=1;
	while(N<mx)N<<=1,++cn;
	for(int i=1;i<N;++i)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<cn);
	int cf=0,cg=0;
	for(int i=L[l];i!=R[l];++i)F[cf++]=S[i];
	for(int i=L[o];i!=R[o];++i)G[cg++]=S[i];
	while(cf!=N)F[cf++]=0;while(cg!=N)G[cg++]=0;
	NTT(F,0);NTT(G,0);
	for(int i=0;i<N;++i)F[i]=1ll*F[i]*G[i]%mod;
	NTT(F,1);
	for(int i=0;i<mx;++i)S[L[l]+i]=F[i];
	R[l]=L[l]+mx;
}
int GO[maxn],iac[maxn*2],fac[maxn*2];
int binom(int n,int m){
	return 1ll*iac[m]*iac[n-m]%mod*fac[n]%mod;
}
int a[maxn*2];
int main(){
	int n;read(n);
	GO[0]=1;
	for(int i=1;i<=n;++i)
		GO[i]=1ll*GO[i-1]*(i*2-1)%mod;
	iac[0]=iac[1]=fac[0]=fac[1]=1;
	for(int i=2;i<=n*2;++i)
		iac[i]=1ll*(mod-mod/i)*iac[mod%i]%mod;
	for(int i=2;i<=n*2;++i)
		iac[i]=1ll*iac[i-1]*iac[i]%mod,fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=1;i<=n*2;++i)read(a[i]);
	sort(a+1,a+n*2+1);int cnt=0,num=0;
	for(int l=1,r=l;l<=n*2;l=r=r+1){
		while(r+1<=n*2&&a[r+1]==a[l])++r;
		int len=r-l+1;++num;L[num]=cnt;
		for(int x=0;x*2<=len;++x)
			S[cnt++]=1ll*GO[x]*binom(len,x*2)%mod;
		R[num]=cnt;
	}
	solve(1,num);
	int mx=R[1]-L[1],delta=L[1],ans=0;
  orzarr(S, mx);
	for(int i=0;i<mx;++i){
		int tmp=1ll*GO[n-i]*(S+delta)[i]%mod;
		if(i&1)tmp=mo(mod-tmp);
		ans=mo(ans+tmp);
	}
	write(ans),pc('\n');
	return 0;
}