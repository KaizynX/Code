#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=200005;
int N,Q,a[maxn];
struct tree
{
    int l,r;
    long long sum,add;
}tr[4*maxn];

void build_tree(int l,int r,int i)
{
    tr[i].l=l;
    tr[i].r=r;
    if(l==r)
    {
        tr[i].sum=a[l];
        return;
    }
    int mid=(tr[i].l+tr[i].r)/2;
    build_tree(l,mid,i*2);
    build_tree(mid+1,r,i*2+1);
    tr[i].sum=tr[i*2].sum+tr[i*2+1].sum;
}

void push_down(int i,int len)
{
    if(tr[i].add)
    {
        tr[i*2].add+=tr[i].add;
        tr[i*2+1].add+=tr[i].add;
        tr[i*2].sum+=tr[i].add*(len-len/2);
        tr[i*2+1].sum+=tr[i].add*(len/2);
        tr[i].add=0;
    }
}

void update_tree(int l,int r,int v,int i)
{
    if(tr[i].l>=l&&tr[i].r<=r)
    {
        tr[i].add+=v;
        tr[i].sum+=(tr[i].r-tr[i].l+1)*v;
        return;
    }
    int mid=(tr[i].l+tr[i].r)/2;
    push_down(i,tr[i].r-tr[i].l+1);//it is must,but why
    if(l>mid)
        update_tree(l,r,v,i*2+1);
    else if(r<=mid)
        update_tree(l,r,v,i*2);
    else
    {
        update_tree(l,r,v,i*2+1);
        update_tree(l,r,v,i*2);
    }
    tr[i].sum=tr[i*2].sum+tr[i*2+1].sum;
}

long long query_tree(int l,int r,int i)
{
    if(tr[i].l>=l&&tr[i].r<=r)
        return tr[i].sum;
    push_down(i,tr[i].r-tr[i].l+1);
    int mid=(tr[i].l+tr[i].r)/2;
    if(l>mid)
        return query_tree(l,r,i*2+1);
    else if(r<=mid)
        return query_tree(l,r,i*2);
    else
        return query_tree(l,r,i*2)+query_tree(l,r,i*2+1);
}

int main()
{
    int i,ope,x,y,v;
    scanf("%d",&N);
    for(i=1;i<=N;++i)
        scanf("%d",a+i);
    build_tree(1,N,1);
    scanf("%d",&Q);
    for(i=0;i<Q;++i)
    {
        scanf("%d%d%d",&ope,&x,&y);
        if(ope==1)
        {
            scanf("%d",&v);
            update_tree(x,y,v,1);
        }
        else
            printf("%lld\n",query_tree(x,y,1));
    }
    return 0;
}
