#include <iostream>
#include <cstdio>
#define LL long long
//TLE
using namespace std;
const int maxn=500005;
int N,M,a[maxn];
struct tree
{
    int l,r;
    LL sum,add;
}tr[maxn*4];

void build_tree(int x,int y,int i)
{
    tr[i].l=x;
    tr[i].r=y;
    if(x==y)
    {
        tr[i].sum=a[x];
        return;
    }
    int mid=(x+y)/2;
    build_tree(x,mid,i*2);
    build_tree(mid+1,y,i*2+1);
    tr[i].sum=tr[i*2].sum+tr[i*2+1].sum;
}

void push_down(int i)
{
    if(tr[i].add)
    {
        int len=tr[i].r-tr[i].l+1;
        tr[i*2].add+=tr[i].add;
        tr[i*2+1].add+=tr[i].add;
        tr[i*2].sum+=tr[i].add*(len-len/2);
        tr[i*2+1].sum+=tr[i].add*(len/2);
        tr[i].add=0;
    }
}

void update_tree(int x,int y,int k,int i)
{
    if(tr[i].l>=x&&tr[i].r<=y)
    {
        tr[i].add+=k;
        tr[i].sum+=(tr[i].r-tr[i].l+1)*k;
        return;
    }
    push_down(i);
    int mid=(tr[i].r+tr[i].l)/2;
    if(y<=mid)
        update_tree(x,y,k,i*2);
    else if(x>mid)
        update_tree(x,y,k,i*2+1);
    else
    {
        update_tree(x,y,k,i*2);
        update_tree(x,y,k,i*2+1);
    }
    tr[i].sum=tr[i*2].sum+tr[i*2+1].sum;
}

LL query_tree(int x,int i)
{
    if(tr[i].l==x&&tr[i].r==x)
        return tr[i].sum;
    push_down(i);
    int mid=(tr[i].r+tr[i].l)/2;
    if(x<=mid)
        return query_tree(x,i*2);
    else if(x>mid)
        return query_tree(x,i*2+1);
    else
        return query_tree(x,i*2)+query_tree(x,i*2+1);
}

int main()
{
    int i,ope,x,y,k;
    scanf("%d%d",&N,&M);
    for(i=1;i<=N;++i)
        scanf("%d",a+i);
    build_tree(1,N,1);
    for(i=1;i<=M;++i)
    {
        scanf("%d%d",&ope,&x);
        if(ope==1)
        {
            scanf("%d%d",&y,&k);
            update_tree(x,y,k,1);
        }
        else if(ope==2)
            printf("%lld\n",query_tree(x,1));
    }
    return 0;
}
