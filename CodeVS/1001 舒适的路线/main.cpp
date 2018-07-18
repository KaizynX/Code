#include <iostream>
#include <cstdio>
#include <algorithm>
#define NO "IMPOSSIBLE\n"
#define sf start_father()
#define ff find_father
using namespace std;
const int maxn=500+5;
const int maxm=5000+5;
const int INF=0x7fffffff;
int n,m,s,t,f[maxn],fi,fj,ans[2]={INF,1};
struct R
{
    int x,y,v;
    bool operator < (const R & a)const
    {
        return v<a.v;
    }
}r[maxm];

void start_father()
{
    for(int i=1;i<=n;++i)
        f[i]=i;
}

int find_father(int son)
{
    int father=f[son];
    if(son!=father)
        father=ff(father);
    f[son]=father;
    return father;
}

void connect(int x,int y)
{
    int fx=ff(x),fy=ff(y);
    if(fx!=fy)
        f[fx]=fy;
}

void minans(int maxv,int minv)
{
    /**
    compare a/b and c/d
    turn to ad/bd and cb/bd
    then compare ad and cb
    **/
    long long ad=ans[0]*minv,cb=maxv*ans[1];
    if((ans[0]==INF&&ans[1]==1)||cb<ad)
    {
        ans[0]=maxv;
        ans[1]=minv;
    }
}

int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

void print()
{
    if(ans[0]%ans[1]==0)
        printf("%d\n",ans[0]/ans[1]);
    else
    {
        int g=gcd(ans[0],ans[1]);
        printf("%d/%d\n",ans[0]/g,ans[1]/g);
    }
}

void solve()
{
    int i,j;
    for(i=0;i<m;++i)
    {
        sf;
        for(j=i;j>=0;--j)
        {
            connect(r[j].x,r[j].y);
            if(ff(s)==ff(t))
                minans(r[i].v,r[j].v);
        }
    }
    if(ans[0]==INF)
        printf(NO);
    else print();
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
        scanf("%d%d%d",&r[i].x,&r[i].y,&r[i].v);
    sort(r,r+m);
    scanf("%d%d",&s,&t);
    solve();
    return 0;
}
