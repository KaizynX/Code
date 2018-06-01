#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=100000+5;

int n,m,k,p;
bool vis[maxn];

struct node
{
    int pre,nex;
}a[maxn];

void putpre(int i,int j)//k i -- k j i
{
    int k=a[i].pre;
    a[k].nex=j;
    a[i].pre=j;
    a[j].nex=i;
    a[j].pre=k;
}

void putnex(int i,int j)//i k -- i j k
{
    int k=a[i].nex;
    a[k].pre=j;
    a[i].nex=j;
    a[j].pre=i;
    a[j].nex=k;
}

void del(int k)
{
    int pre=a[k].pre;
    int nex=a[k].nex;
    a[pre].nex=nex;
    a[nex].pre=pre;
}

inline void print()
{
    int now=1;
    while(a[now].pre!=0)
    {
        now=a[now].pre;
    }
    while(a[now].nex!=0)
    {
        printf("%d ",now);
        now=a[now].nex;
    }
    printf("%d\n",now);
}

int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;++i)
    {
        scanf("%d%d",&k,&p);
        if(p==0)
            putpre(k,i);
        else if(p==1)
            putnex(k,i);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;++i)
    {
        scanf("%d",&k);
        if(vis[k])continue;
        vis[k]=1;
        del(k);
    }
    print();
    return 0;
}
