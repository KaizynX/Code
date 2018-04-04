#include <iostream>
#include <cstdio>
using namespace std;
const int N=500000+5;
int n,m,tr[N];

inline int lowbit(int x)
{
    return x&-x;
}

void update(int x,int k)
{
    while(x<=n)
    {
        tr[x]+=k;
        x+=lowbit(x);
    }
}

int query(int x)
{
    int sum=0;
    while(x>0)
    {
        sum+=tr[x];
        x-=lowbit(x);
    }
    return sum;
}

int main()
{
    int i,ope,x,y,a;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&a);
        update(i,a);
    }
    while(m--)
    {
        scanf("%d%d%d",&ope,&x,&y);
        if(ope==1)
            update(x,y);
        else if(ope==2)
            printf("%d\n",query(y)-query(x-1));
    }
    return 0;
}
