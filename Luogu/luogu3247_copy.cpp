/*
 * @Author: Kaizyn
 * @Date: 2021-03-17 16:49:38
 * @LastEditTime: 2021-03-17 17:42:58
 */
#include<bits/stdc++.h>
#define fp(i,a,b) for(register int i=a,I=b+1;i<I;++i)
#define fd(i,a,b) for(register int i=a,I=b-1;i>I;--i)
#define go(u) for(register int i=fi[u],v=e[i].to;i;v=e[i=e[i].nx].to)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
char ss[1<<17],*A=ss,*B=ss;
inline char gc(){return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?-1:*A++;}
template<class T>inline void sd(T&x){
  char c;T y=1;while(c=gc(),(c<48||57<c)&&c!=-1)if(c==45)y=-1;x=c-48;
  while(c=gc(),47<c&&c<58)x=x*10+c-48;x*=y;
}
const int N=1e5+5;
typedef int arr[N];
struct eg{
  int u,v,a,b,k;
  inline void in(){sd(u),sd(v),sd(a),sd(b);}
}a[N],b[N],c[N],d[N];
int n,m,q,Top;arr fa,sz,Am,Bm,ans;
inline bool cpa(const eg a,const eg b){return a.a==b.a?a.b<b.b:a.a<b.a;}
inline bool cpb(const eg a,const eg b){return a.b==b.b?a.a<b.a:a.b<b.b;}
int gf(int x){return fa[x]==x?x:gf(fa[x]);}
inline void merge(int u,int v,int a,int b){
  u=gf(u),v=gf(v);if(sz[u]>sz[v])swap(u,v);
  d[++Top]={u,v,Am[v],Bm[v],sz[v]};
  if(u^v)fa[u]=v,sz[v]+=sz[u],
    cmax(Am[v],Am[u]),cmax(Bm[v],Bm[u]);
  cmax(Am[v],a),cmax(Bm[v],b);
}
int main(){
  #ifndef ONLINE_JUDGE
    file("s");
  #endif
  sd(n),sd(m);
  fp(i,1,m)a[i].in();
  sd(q);
  fp(i,1,q)b[i].in(),b[i].k=i;
  sort(a+1,a+m+1,cpa);sort(b+1,b+q+1,cpb);
  register int Sz=sqrt(m*log2(n)),i,j,k,l;
  for(i=1;i<=m;i+=Sz){
    fp(j,1,n)fa[j]=j,Am[j]=Bm[j]=-1,sz[j]=1;
    int Sum=0;
    fp(j,1,q)if(a[i].a<=b[j].a&&
      (b[j].a<a[i+Sz].a||i+Sz>m))c[++Sum]=b[j];
    if(!Sum)continue;if(i^1)sort(a+1,a+i,cpb);
    for(j=k=1;j<=Sum;++j){
      for(;k<i&&a[k].b<=c[j].b;++k)
        merge(a[k].u,a[k].v,a[k].a,a[k].b);
      Top=0;
      for(l=i;l<i+Sz&&l<=m;++l)
        if(a[l].a<=c[j].a&&a[l].b<=c[j].b)
          merge(a[l].u,a[l].v,a[l].a,a[l].b);
      int u=gf(c[j].u),v=gf(c[j].v);
      ans[c[j].k]=(u==v&&Am[u]==c[j].a&&Bm[u]==c[j].b);
      fd(l,Top,1){
        u=d[l].u,v=d[l].v;fa[u]=u;
        Am[v]=d[l].a,Bm[v]=d[l].b,sz[v]=d[l].k;
      }Top=0;
    }
  }
  fp(i,1,q)puts(ans[i]?"Yes":"No");
return 0;
}
