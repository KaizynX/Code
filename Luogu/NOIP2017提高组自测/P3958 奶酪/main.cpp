#include <iostream>
#include <cstdio>
#include <cmath>
#define LL long long
using namespace std;
const int maxn=1000+5;
const int maxr=1000000000+5;

int T,n,h,r,x,y,z,f[maxn];
struct yuan
{
    int x,y,z;
}s[maxn];

LL read()
{
    LL res=0;
    char c;
    c=getchar();
    while(c<'0' || c>'9')
        c=getchar();
    while(c>='0' && c<='9')
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

inline void init()
{
    for(int i=0;i<=n+1;++i)
    {
        f[i]=i;
    }
}

inline LL dist(int i,int j)
{
    int x1=s[i].x,x2=s[j].x,y1=s[i].y,y2=s[j].y,z1=s[i].z,z2=s[j].z;
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}

int ff(int s)
{
    if(f[s]!=s)
        f[s]=ff(f[s]);
    return f[s];
}

void connect(int i,int j)
{
    int fi=ff(i),fj=ff(j);
    if(fi!=fj)
        f[fi]=f[j];
}

int main()
{
    //freopen("testdata.in","w",stdin);//
    //freopen("3958.out","w",stdout);//
    int i,j;
    T=read();
    while(T--)
    {
        n=read();
        h=read();
        r=read();
        init();
        for(i=1;i<=n;++i)
        {
            s[i].x=read();
            s[i].y=read();
            s[i].z=read();
            if(s[i].z-r<=0)
                connect(0,i);
            if(s[i].z+r>=h)
                connect(n+1,i);
        }
        for(i=1;i<n;++i)
        {
            for(j=i+1;j<=n;++j)
            {
                if(dist(i,j)<=r*2)
                    connect(i,j);
            }
        }
        if(ff(0)==ff(n+1))
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
