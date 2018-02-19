#include <iostream>
#include <cstdio>
#define LL long long
using namespace std;
const int N = 100000+5;

int n,m,p,a[N];

struct tree
{
    int l,r;
    LL add,mul,sum;
}tr[N*10];//don't know why

int read()
{
    int res=0;
    char c;
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        res=res*10+(c-'0');
        c=getchar();
    }
    return res;
}

void build_tree(int x,int y,int i)
{
    tr[i].l=x;
    tr[i].r=y;
    tr[i].mul=1;//
    if(x==y)
    {
        tr[i].sum=a[x];
        return;
    }
    int mid=(x+y)/2;
    build_tree(x,mid,i*2);
    build_tree(mid+1,y,i*2+1);
    tr[i].sum=(tr[i*2].sum+tr[i*2+1].sum)%p;
}

inline void push_down(int i)
{
    int len=(tr[i].r-tr[i].l)+1;
    tr[i*2].sum=(tr[i*2].sum*tr[i].mul+tr[i].add*(len-len/2))%p;
    tr[i*2+1].sum=(tr[i*2+1].sum*tr[i].mul+tr[i].add*(len/2))%p;
    tr[i*2].mul=(tr[i*2].mul*tr[i].mul)%p;
    tr[i*2+1].mul=(tr[i*2+1].mul*tr[i].mul)%p;
    tr[i*2].add=(tr[i*2].add+tr[i].add)%p;
    tr[i*2+1].add=(tr[i*2+1].add+tr[i].add)%p;
    tr[i].add=0;
    tr[i].mul=1;
}

void update_add(int x,int y,int k,int i)
{
    if(x<=tr[i].l&&y>=tr[i].r)
    {
        tr[i].add=(tr[i].add+k)%p;
        tr[i].sum=(tr[i].sum+k*(tr[i].r-tr[i].l+1))%p;
        return;
    }
    push_down(i);
    int mid=(tr[i].r+tr[i].l)/2;
    if(y<=mid)
        update_add(x,y,k,i*2);
    else if(x>mid)
        update_add(x,y,k,i*2+1);
    else
    {
        update_add(x,y,k,i*2);
        update_add(x,y,k,i*2+1);
    }
    tr[i].sum=(tr[i*2].sum+tr[i*2+1].sum)%p;
}

void update_mul(int x,int y,int k,int i)
{
    if(x<=tr[i].l&&y>=tr[i].r)
    {
        tr[i].sum=(tr[i].sum*k)%p;
        tr[i].mul=(tr[i].mul*k)%p;
        tr[i].add=(tr[i].add*k)%p;
        return;
    }
    push_down(i);
    int mid=(tr[i].r+tr[i].l)/2;
    if(y<=mid)
        update_mul(x,y,k,i*2);
    else if(x>mid)
        update_mul(x,y,k,i*2+1);
    else
    {
        update_mul(x,y,k,i*2);
        update_mul(x,y,k,i*2+1);
    }
    tr[i].sum=(tr[i*2].sum+tr[i*2+1].sum)%p;
}

int query_tree(int x,int y,int i)
{
    if(x<=tr[i].l&&y>=tr[i].r)
        return tr[i].sum;
    push_down(i);
    int mid=(tr[i].r+tr[i].l)/2;
    if(y<=mid)
        return query_tree(x,y,i*2);
    else if(x>mid)
        return query_tree(x,y,i*2+1);
    else
        return query_tree(x,y,i*2)+query_tree(x,y,i*2+1);
    tr[i].sum=(tr[i*2].sum+tr[i*2+1].sum)%p;
}

int main()
{
    int i,ope,x,y,k;
    n=read();
    m=read();
    p=read();
    for(i=1;i<=n;++i)
        a[i]=read();
    build_tree(1,n,1);
    while(m--)
    {
        ope=read();
        x=read();
        y=read();
        if(ope==3)
        {
            printf("%d\n",query_tree(x,y,1)%p);
            continue;
        }
        k=read();
        if(ope==1)
            update_mul(x,y,k,1);
        else if(ope==2)
            update_add(x,y,k,1);
    }
    return 0;
}
