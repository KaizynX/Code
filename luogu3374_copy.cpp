#include<cstdio>
using namespace std;
inline char gc(){
    static char buf[1<<17],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<17,stdin),p1==p2)?EOF:*p1++;
}
template<class T>
inline bool read(T&n){
    char ch=gc();int sign=1;
    for(n=0;(ch<'0'||ch>'9')&&ch!='-'&&ch!=EOF;ch=gc()); if(ch==EOF) return 0;
    for(ch=='-'?ch=gc(),sign=-1:0;ch>='0'&&ch<='9';ch=gc()) n=(n<<1)+(n<<3)+ch-'0';n*=sign;return 1;
}
char buf[1<<17],*p1=buf,*p2=buf+(1<<17);
inline void pc(char ch){
    *(p1++)=ch,p1==p2?fwrite(buf,1,p1-buf,stdout),p1=buf:0;
}
template<class T>
inline void write(T val){
    if(val<0)pc('-'),val=-val;if(!val)pc('0');
    int num=0;char ch[24];
    while(val)ch[++num]=val%10+'0',val/=10;while(num)pc(ch[num--]);
    pc('\n');
}
int c[500010],n,m,a,b;
inline int lowbit(int x){return x&(-x);}
inline void add(int x,int y){while(x<=n)c[x]+=y,x+=lowbit(x);}
inline int getsum(int x){int sum=0;while(x)sum+=c[x],x-=lowbit(x);return sum;}
int main()
{
    read(n),read(m);
    for(int i=1;i<=n;i++)read(a),add(i,a);
    for(int i=1;i<=m;i++)
    {
        read(a);
        if(a==1)read(a),read(b),add(a,b);
        else read(a),read(b),write(getsum(b)-getsum(a-1)); 
    }
    fwrite(buf,1,p1-buf,stdout);
    return 0;
}
