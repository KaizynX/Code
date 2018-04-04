#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=30005;
int N,M,flag=1;
struct tree
{
    int l,r,sum;
}tr[maxn*4];

void build_tree(int x,int y,int i)
{
    tr[i].l=x;
    tr[i].r=y;
    if(x==y)return;
    int mid=(x+y)/2;
    build_tree(x,mid,i*2);
    build_tree(mid+1,y,i*2+1);
}

void update_tree(int x,int i)
{
    if(tr[i].l==x&&tr[i].r==x)
    {
        tr[i].sum=1;
        return;
    }
    int mid=(tr[i].l+tr[i].r)/2;
    if(x<=mid)
        update_tree(x,i*2);
    else if(x>mid)
        update_tree(x,i*2+1);
    tr[i].sum=tr[i*2].sum+tr[i*2+1].sum;
}

int query_tree(int x,int y,int i)
{
    if(tr[i].l>=x&&tr[i].r<=y)
        return tr[i].sum;
    int mid=(tr[i].l+tr[i].r)/2;
    if(y<=mid)
        return query_tree(x,y,i*2);
    else if(x>mid)
        return query_tree(x,y,i*2+1);
    else
        return query_tree(x,y,i*2)+query_tree(x,y,i*2+1);
}

void del(int &form)
{
    int cur=form+M,que;
    if(cur>N)
    {
        cur-=N;
        que=query_tree(1,cur,1)+query_tree(form,N,1);
    }
    else que=query_tree(form,cur,1);
    while(que!=0)
    {
        int ccur=cur+1;
        if(ccur>N)
        {
            ccur-=N;
            cur=ccur+que-1;
        }
        else cur+=que;
        if(cur>N)
        {
            cur-=N;
            que=query_tree(1,cur,1)+query_tree(ccur,N,1);
        }
        else que=query_tree(ccur,cur,1);
    }
    update_tree(cur,1);
    form=cur+1;
    if(form>N)
        form-=N;
    printf("%d ",cur);
}

int main()
{
    int i,n;
    scanf("%d%d",&N,&M);
    build_tree(1,N,1);
    M--;
    n=N;
    while(n--)
        del(flag);
    printf("\n");
    return 0;
}
