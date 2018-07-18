#include <iostream>
#include <cstdio>

using namespace std;

const int maxn=100000+5;

int n,a[maxn],r[maxn];
unsigned long long ans;

int getint();

void msort(int s,int t)
{
    if(s==t)return;
    int mid=(s+t)/2;
    msort(s,mid);
    msort(mid+1,t);
    int i=s,j=mid+1,k=s;
    while(i<=mid && j<=t)
    {
        if(a[i]<=a[j])
        {
            r[k++]=a[i++];
        }
        else if(a[i]>a[j])//what we want
        {
            r[k++]=a[j++];
            ans+=mid-i+1;//how many i bigger than j
        }
    }
    while(i<=mid)
        r[k++]=a[i++];
    while(j<=t)
        r[k++]=a[j++];

    for(i=s;i<=t;++i)
        a[i]=r[i];
}

int main()
{
    n=getint();
    for(int i=1;i<=n;++i)
        a[i]=getint();
    msort(1,n);
    printf("%lld\n",ans);
    return 0;
}

int getint()
{
    int res=0;
    char c=getchar();
    while(c<'0' || c>'9')
        c=getchar();
    while(c>='0' && c<='9')
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}
