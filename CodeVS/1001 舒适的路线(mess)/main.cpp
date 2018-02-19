#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxm=5005;
const int maxn=505;
const int INF=0x7fffffff;
int N,M,f[maxn],ans[2]={INF,1};
struct rode
{
    int x,y,v;
}r[maxm];

bool cmp(rode a,rode b)
{
    return a.v<b.v;
}

void sf()
{
    for(int i=1;i<=N;++i)
        f[i]=i;
}

int ff(int s)
{
    int fa=f[s];
    if(fa!=s)fa=ff(fa);
    f[s]=fa;
    return fa;
}

void connect(int x,int y)
{
    int fx=ff(x),fy=ff(y);
    if(fx!=fy)
        f[fx]=fy;
}

void minans(int maxl,int minl)
{
    long long ansa=ans[0],ansb=ans[1],na=maxl,nb=minl;
    ansa*=nb;
    na*=ansb;
    if(na<ansa)
    {
        ans[0]=maxl;
        ans[1]=minl;
    }
}

void print()
{
    int t,a=ans[0],b=ans[1];
    while(a%b!=0)
    {
        t=a%b;
        a=b;
        b=t;
    }
    ans[0]/=b;
    ans[1]/=b;
    printf("%d/%d\n",ans[0],ans[1]);
}

void solve(int s,int t)
{
    int i,j,minl,maxl;
    for(i=0;i<M;++i)
    {
        sf();//father
        maxl=r[i].v;
        for(j=i;j>=0;--j)
        {
            connect(r[j].x,r[j].y);
            minl=r[j].v;
            if(ff(s)==ff(t))
                minans(maxl,minl);
        }
    }
    if(ans[0]==INF)printf("IMPOSSIBLE\n");
    else if(ans[0]%ans[1]==0)printf("%d\n",ans[0]/ans[1]);
    else print();
}

int main()
{
    int i,s,t;
    scanf("%d%d",&N,&M);
    for(i=0;i<M;++i)
        scanf("%d%d%d",&r[i].x,&r[i].y,&r[i].v);
    scanf("%d%d",&s,&t);
    sort(r,r+M,cmp);
    solve(s,t);
    return 0;
}
/*****
5 5
1 2 30000
1 2 29999
3 4 1
4 5 2
5 3 3
1 2

1
*****/
