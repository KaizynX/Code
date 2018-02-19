#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1000+5;
const int maxm=100000+5;
int n,m,f[maxn];
struct node
{
    int x,y,t;
    bool operator < (const node b)const
    {
        return t<b.t;
    }
}a[maxm];

int read()
{
    int res=0;
    char c;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

inline void init()
{
    for(int i=1;i<=n;++i)
        f[i]=i;
}

int ff(int s)
{
    if(f[s]!=s)f[s]=ff(f[s]);
    return f[s];
}

bool connect(int x,int y)
{
    int fx=ff(x),fy=ff(y);
    if(fx==fy)return 0;
    f[x]=fy;
    return 1;
}

int main()
{
    int cnt=0,ans=0;
    n=read();
    m=read();
    init();
    for(int i=0;i<m;++i)
    {
        a[i].x=read();
        a[i].y=read();
        a[i].t=read();
    }
    sort(a,a+m);
    for(int i=0;i<m;++i)
    {
        if(connect(a[i].x,a[i].y))
            cnt++;
        if(cnt>=n-1)
        {
            printf("%d\n",a[i].t);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
