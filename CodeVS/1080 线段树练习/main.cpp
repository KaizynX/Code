#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100005;
const int maxm=10005;
int N,M,n[maxn];
struct tree
{
    int l,r;
    long long sum;
}tr[4*maxn];

void build_tree(int x,int y,int i)
{
    tr[i].l=x;
    tr[i].r=y;
    if(x==y)
        tr[i].sum=n[x];
    else
    {
        int mid=(x+y)/2;
        build_tree(x,mid,i*2);
        build_tree(mid+1,y,i*2+1);
        tr[i].sum=tr[i*2].sum+tr[i*2+1].sum;
    }
}

void update_tree(int q,int val,int i)
{
    if(tr[i].l==q&&tr[i].r==q)
        tr[i].sum+=val;
    else
    {
        int mid=(tr[i].l+tr[i].r)/2;
        if(q<=mid)
            update_tree(q,val,i*2);
        else if(q>mid)
            update_tree(q,val,i*2+1);
        tr[i].sum=tr[i*2].sum+tr[i*2+1].sum;
    }
}

long long query_tree(int x,int y,int i)
{
    if(x<=tr[i].l&&y>=tr[i].r)
        return tr[i].sum;
    int mid=(tr[i].l+tr[i].r)/2;
    if(y<=mid)
        query_tree(x,y,i*2);
    else if(x>mid)
        query_tree(x,y,i*2+1);
    else
        return query_tree(x,y,i*2)+query_tree(x,y,i*2+1);
}

int main()
{
    int i,ope,a,b;
    scanf("%d",&N);
    for(i=1;i<=N;++i)
        scanf("%d",n+i);
    build_tree(1,N,1);
    scanf("%d",&M);
    for(i=1;i<=M;++i)
    {
        scanf("%d%d%d",&ope,&a,&b);
        if(ope==1)
            update_tree(a,b,1);
        else if(ope==2)
            printf("%lld\n",query_tree(a,b,1));
    }
    return 0;
}
