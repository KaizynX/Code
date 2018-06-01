#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=10000;

struct tree
{
    int l,r,f;
}tr[maxn];

int ff(int i)
{
    while(tr[i].f!=0)
        i=tr[i].f;
    return i;
}

void print(int i)
{
    if(i==0)return;
    putchar(i);
    print(tr[i].l);
    print(tr[i].r);
}

int main()
{
    int n;
    char f,l,r;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        cin>>f>>l>>r;
        if(l=='*')l=0;
        if(r=='*')r=0;
        tr[f].l=l;
        tr[f].r=r;
        tr[l].f=f;
        tr[r].f=f;
    }
    f=ff(f);
    print(f);
    return 0;
}
