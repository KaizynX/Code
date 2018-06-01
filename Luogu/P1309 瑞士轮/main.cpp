#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=100000+5;
const int maxr=50+5;

int n,r,q;

struct er
{
    int b,s,w;
    bool operator < (const er c)const
    {
        if(s<c.s)return 0;
        else if(s>c.s)return 1;
        return b<c.b;
    }
}win[maxn],fal[maxn],a[2*maxn];

inline void in();
inline int getint();

int main()
{
    in();
    sort(a+1,a+1+2*n);
    while(r--)
    {
        for(int i=1;i<=n;++i)
        {
            if(a[i*2-1].w<a[i*2].w)
            {
                a[i*2].s++;
                win[i]=a[i*2];
                fal[i]=a[i*2-1];
            }
            else
            {
                a[i*2-1].s++;
                win[i]=a[i*2-1];
                fal[i]=a[i*2];
            }
        }
        //msort
        int wi=1,fi=1,ai=1;
        while(wi<=n && wi<=n)
        {
            if(win[wi]<fal[fi])
            {
                a[ai++]=win[wi++];
            }
            else
            {
                a[ai++]=fal[fi++];
            }
        }
        while(wi<=n)
            a[ai++]=win[wi++];
        while(fi<=n)
            a[ai++]=fal[fi++];
    }
    printf("%d\n",a[q].b);
    return 0;
}

inline void in()
{
    n=getint();
    r=getint();
    q=getint();
    for(int i=1;i<=2*n;++i)
    {
        a[i].b=i;
    }
    for(int i=1;i<=2*n;++i)
    {
        a[i].s=getint();
    }
    for(int i=1;i<=2*n;++i)
    {
        a[i].w=getint();
    }
}

inline int getint()
{
    char c=getchar();
    int res=0;
    while(c<'0' || c>'9')
        c=getchar();
    while(c>='0' && c<='9')
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}
