#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=85;
int n,m;
struct node
{
    int num[maxn],len;
}f[maxn][maxn];

node a[maxn],ans,fhead,ftail;

void itoc(node* a,int b)
{
    memset(&(*a),0,sizeof (*a));
    int d;
    (*a).len=0;
    if(b==0)(*a).len=1;
    while(b>0)
    {
        d=b%10;
        (*a).num[++(*a).len]=d;
        b/=10;
    }
}

void hplus(node a,node b,node* ans)//AC
{
    memset((*ans).num,0,sizeof (*ans).num);
    int l=max(a.len,b.len),cur,ansl;
    for(int i=1;i<=l;++i)
    {
        cur=a.num[i]+b.num[i];
        (*ans).num[i]+=cur;
        ansl=i;
        while((*ans).num[ansl]>9)
        {
            (*ans).num[ansl+1]+=(*ans).num[ansl]/10;
            (*ans).num[ansl]%=10;
            ansl++;
        }
    }
    if((*ans).num[l+1])
        (*ans).len=l+1;
    else (*ans).len=l;
}

void hmulti(node a,node* ans)
{
    memset((*ans).num,0,sizeof (*ans).num);
    int cur;
    for(int i=1;i<=a.len;++i)
    {
        cur=a.num[i]*2;
        (*ans).num[++(*ans).len]+=cur%10;
        (*ans).num[(*ans).len+1]+=cur/10;
    }
    if((*ans).num[a.len+1])
        (*ans).len=a.len+1;
    else (*ans).len=a.len;
}

bool cmp(node a,node b)//a big 1
{
    if(a.len>b.len)return 1;
    else if(a.len<b.len)return 0;
    int l=a.len,na,nb;
    for(int i=l;i>=1;--i)
    {
        na=a.num[i];
        nb=b.num[i];
        if(na>nb)return 1;
        else if(nb>na)return 0;
    }
    return 0;//a==b
}

void print(node a)
{
    for(int i=a.len;i>=1;--i)
        printf("%d",a.num[i]);
}

int main()
{
    scanf("%d%d",&n,&m);
    int i,j,b,l,x,y;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
        {
            scanf("%d",&b);
            itoc(&a[j],b);
            //f[j][j]=a[j]*2
            hmulti(a[j],&f[j][j]);
        }
        for(l=2;l<=m;++l)
            for(x=1;x<=m-l+1;++x)
            {
                y=x+l-1;
                //f[x][y]=max(a[x]+f[x+1][y],f[x][y-1]+a[y])*2;
                hplus(a[x],f[x+1][y],&fhead);
                hplus(a[y],f[x][y-1],&ftail);
                if(cmp(fhead,ftail))
                    hmulti(fhead,&f[x][y]);
                else
                    hmulti(ftail,&f[x][y]);
            }
        hplus(f[1][m],ans,&ans);
        memset(&f,0,sizeof f);
    }
    print(ans);
    printf("\n");
    return 0;
}
