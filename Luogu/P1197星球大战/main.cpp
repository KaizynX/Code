#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=400000+5;
struct node
{
    int u,v;
    bool operator < (const node b)const
    {
        return u<b.u;
    }
}q[maxn];
int n,m,k;
int f[maxn],ans[maxn],ope[maxn],pos[maxn];
bool flag[maxn],use[maxn];

int read();
int ff(int s);
inline void in();
inline void out();
inline void init();

int main()
{
    int i,j,u,v,now,fu,fv;
    in();
    init();
    now=n;
    for(i=1;i<=n;++i)
    {
        if(flag[i])
            continue;
        fu=ff(i);
        for(j=pos[i-1]+1;j<=pos[i];++j)
        {
            v=q[j].v;
            if(flag[v])
                continue;
            fv=ff(v);
            if(fu==fv)
                continue;
            f[fv]=fu;
            now--;
        }
    }
    now-=k;
    ans[k]=now;

    for(i=k;i>0;--i)
    {
        now++;
        u=ope[i];
        flag[u]=0;
        fu=ff(u);
        for(j=pos[u-1]+1;j<=pos[u];++j)
        {
            v=q[j].v;
            if(flag[v])
                continue;
            fv=ff(v);
            if(fu==fv)
                continue;
            f[fv]=fu;
            now--;
        }
        ans[i-1]=now;
    }
    out();
    return 0;
}

int read()
{
    int res=0;
    char c;
    c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

int ff(int s)
{
    if(f[s]!=s)
        f[s]=ff(f[s]);
    return f[s];
}

inline void in()
{
    int i,j,u,v;
    n=read();
    m=read();
    for(i=1;i<=m;++i)
    {
        u=read()+1;
        v=read()+1;
        q[i*2-1].u=u;
        q[i*2-1].v=v;
        q[i*2].u=v;
        q[i*2].v=u;
    }
    k=read();
    for(i=1;i<=k;++i)
    {
        ope[i]=read()+1;
        flag[ope[i]]=1;
    }
}

inline void out()
{
    for(int i=0;i<=k;++i)
        printf("%d\n",ans[i]);
}

inline void init()
{
    for(int i=1;i<=n;++i)
        f[i]=i;
    sort(q+1,q+1+2*m);
    int cur=1,nu;
    for(int i=1;i<=2*m;++i)
    {
        nu=q[i].u;
        pos[nu]=i;
        if(nu>cur+1)
        {
            for(int j=cur+1;j<nu;++j)
                pos[j]=pos[cur];
        }
        cur=nu;
    }
}
