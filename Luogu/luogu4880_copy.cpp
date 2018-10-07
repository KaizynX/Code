#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 0x7f7f7f7f
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
inline int read(){
    int x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar())  if (ch=='-')    f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar())    x=(x<<1)+(x<<3)+ch-'0';
    return x*f;
}
inline void print(int x){
    if (x>=10)  print(x/10);
    putchar(x%10+'0');
}
const int N=1e5,M=1e6;
int pre[(M<<1)+10],now[N+10],child[(M<<1)+10],val[(M<<1)+10];
int h[N+10],deep[N+10];
bool vis[N+10];
int n,m,S,tot;
struct S1{
    int x,T;
    void insert(int _x,int _T){x=_x,T=_T;}
    bool operator <(const S1 &a)const{return T<a.T;}
}A[N+10];
void join(int x,int y,int z){pre[++tot]=now[x],now[x]=tot,child[tot]=y,val[tot]=z;}
void SPFA(int x){
    int head=0,tail=1;
    memset(deep,63,sizeof(deep));
    h[1]=x,vis[x]=1,deep[x]=0;
    while (head!=tail){
        if (++head>N)   head=1;
        int Now=h[head];
        for (int p=now[Now],son=child[p];p;p=pre[p],son=child[p]){
            if (deep[son]>deep[Now]+val[p]){
                deep[son]=deep[Now]+val[p];
                if (!vis[son]){
                    if (++tail>N)   tail=1;
                    vis[h[tail]=son]=1;
                }
            }
        }
        vis[Now]=0;
    }
}
int main(){
    n=read(),m=read(),S=read(),A[0].insert(read(),0);
    for (int i=1;i<=m;i++){
        int x=read(),y=read(),z=read();
        join(x,y,z),join(y,x,z);
    }
    SPFA(S);
    int T=read();
    for (int i=1;i<=T;i++){
        int x=read(),y=read();
        A[i].insert(y,x);
    }
    A[++T].insert(0,inf);
    sort(A,A+1+T);
    for (int i=0;i<=T;i++){
        if (deep[A[i].x]<A[i+1].T){
            printf("%d\n",max(deep[A[i].x],A[i].T));
            break;
        }
    }
    return 0;
}
