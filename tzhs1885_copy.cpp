#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=1005,B=1e4,W=4,L=1005;
struct people{
    int a,b,t;
}p[N];
bool cmp(people x,people y){
    return x.t<y.t;
}

struct big{
    int size,d[L];
    big(int a=1):size(a){memset(d,0,sizeof(int)*L);}
    
};
bool bigger(big &a,big &b){
    if(a.size>b.size) return true;
    if(a.size<b.size) return false;
    for(int i=a.size-1;i>=0;i++){
        if(a.d[i]>b.d[i]) return true;
    }
    return false;
}
void copy(big &t,big &s){
    t.size=s.size;
    memcpy(t.d,s.d,sizeof(int)*L);
}

void chengInt(big &a,int k){
    int g=0,i;
    for(i=0;i<a.size;i++){
        int tmp=a.d[i]*k;
        a.d[i]=(tmp+g)%B;
        g=(tmp+g)/B;
    }
    while(g){
        a.d[i++]=g%B; a.size++;
        g/=B;
    }
}

void chuInt(big &a,int k){
    int g=0;
    for(int i=a.size-1;i>=0;i--){
        g=g*B+a.d[i];
        a.d[i]=g/k;
        g%=k;
    }
    while(a.d[a.size-1]==0) a.size--;
}
//原来的弱智方法
//void chuInt(big &a,int k,big &ans){
//    while(noSmallInt(a,k))
//    {jianInt(a,k);addInt(ans,1);}
//}
//void chuInt(big &a,int k,int &ans){
//    while(noSmallInt(a,k))
//    {jianInt(a,k);ans++;}
//}
int n;
big s,t,mx;
int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i=0;i<=n;i++){scanf("%d%d",&p[i].a,&p[i].b); p[i].t=p[i].a*p[i].b;}
    sort(p+1,p+n+1,cmp);
    
    s.d[0]=p[0].a;
    for(int i=1;i<=n;i++){for(int i=s.size-1;i>=0;i--)
        copy(t,s);
        chuInt(t,p[i].b);
        if(bigger(t,mx)) copy(mx,t);
        chengInt(s,p[i].a);
    }
    
    for(int i=mx.size-1;i>=0;i--){
        if(i!=mx.size-1){
            if(mx.d[i]<10) cout<<"000";
            else if(mx.d[i]<100) cout<<"00";
            else if(mx.d[i]<1000) cout<<"0";
        }
        cout<<mx.d[i];
    }

}
