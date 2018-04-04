#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=20000+5;
const int maxm=100000+5;
int n,m,f[maxn],e[maxn];//enemy
struct Node
{
    int x,y,v;
    bool operator < (const Node & b)const
    {
        return v>b.v;//from big to small
    }
}a[maxm];

int ff(int son)
{
    int fa=f[son];
    if(son!=fa)
        fa=ff(fa);
    f[son]=fa;
    return fa;
}

void connect(int x,int y)
{
    int fx=ff(x),fy=ff(y);
    f[fx]=fy;
}

int main()
{
    int i,x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
    sort(a+1,a+1+m);
    for(i=1;i<=n;++i)
        f[i]=i;
    for(i=1;i<=m;++i)
    {
        x=a[i].x;
        y=a[i].y;
        if(ff(x)==ff(y))
        {
            printf("%d\n",a[i].v);
            return 0;
        }
        if(e[x]==0&&e[y]==0)//no enemy
        {
            e[x]=y;
            e[y]=x;
        }
        else if(e[x]!=0&&e[y]!=0)
        {
            connect(e[x],y);
            connect(x,e[y]);
        }
        else if(e[x]!=0&&e[y]==0)
        {
            connect(e[x],y);
            e[y]=x;
        }
        else if(e[x]==0&&e[y]!=0)
        {
            connect(e[y],x);
            e[x]=y;
        }
    }
    printf("0\n");
    return 0;
}
