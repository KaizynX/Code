#include <iostream>
#include <cstdio>
#define F 'F'
#define B 'B'
#define I 'I'
using namespace std;

const int maxn=1<<15;

int n;
int a[maxn];
int t[maxn];

void build_tree(int x,int y,int i)
{
    if(x==y)
    {
        if(a[x]==0)t[i]=B;
        else if(a[x]==1)t[i]=I;
        return;
    }
    int mid=(x+y)>>1;
    build_tree(x,mid,i*2);//left
    build_tree(mid+1,y,i*2+1);//right
    if(t[i*2]==F || t[i*2+1]==F)t[i]=F;
    else if(t[i*2]!=t[i*2+1])t[i]=F;
    else if(t[i*2]==t[i*2+1])t[i]=t[i*2];
}

void print(int i)
{
    if(t[i]==0)return;
    print(i*2);
    print(i*2+1);
    putchar(t[i]);
}

int main()
{
    scanf("%d",&n);
    n=1<<n;
    int i=0;
    char c;
    while(1)
    {
        c=getchar();
        if(c=='1')a[++i]=1;
        else if(c=='0')a[++i]=0;
        if(i==n)break;
    }
    build_tree(1,n,1);
    print(1);
    return 0;
}
