#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100005;
int a[maxn],N,Q;
struct tree
{
    int l,r;
    long long sum,add;
}tr[4*maxn];

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

void push_down(int i,int l)
{
    if(tr[i].add)
    {
        tr[i*2].add+=tr[i].add;
        tr[i*2+1].add+=tr[i].add;
        tr[i*2].sum+=tr[i].add*(l-l/2);
        tr[i*2+1].sum+=tr[i].add*(l/2);
        tr[i].add=0;
    }
}

void update_tree(int x,int y,int v,int i)
{
    if(x<=tr[i].l&&y>=tr[i].r)
    {
        tr[i].add+=v;
        tr[i].sum+=v*(tr[i].r-tr[i].l+1);
        return;
    }
    push_down(i,tr[i].r-tr[i].l+1);
    int mid=(tr[i].r+tr[i].l)/2;
    if(x>mid)
        update_tree(x,y,v,i*2+1);
    else if(y<=mid)
        update_tree(x,y,v,i*2);
    else
    {
        update_tree(x,y,v,i*2);
        update_tree(x,y,v,i*2+1);
    }
    tr[i].sum=tr[i*2].sum+tr[i*2+1].sum;
}

long long query_tree(int x,int i)
{
    if(x==tr[i].l&&x==tr[i].r)
        return tr[i].sum;
    push_down(i,tr[i].r-tr[i].l+1);
    int mid=(tr[i].r+tr[i].l)/2;
    if(x>mid)
        return query_tree(x,i*2+1);
    else if(x<=mid)
        return query_tree(x,i*2);
    else
        return query_tree(x,i*2+1)+query_tree(x,i*2);
}

int main()
{
    int i,ope,x,y,v;
    scanf("%d",&N);
    for(i=1;i<=N;++i)
        scanf("%d",a+i);
    build_tree(1,N,1);
    scanf("%d",&Q);
    for(i=1;i<=Q;++i)
    {
        scanf("%d",&ope);
        if(ope==1)
        {
            scanf("%d%d%d",&x,&y,&v);
            update_tree(x,y,v,1);
        }
        else
        {
            scanf("%d",&x);
            printf("%d\n",query_tree(x,1));
        }
    }
    return 0;
}
