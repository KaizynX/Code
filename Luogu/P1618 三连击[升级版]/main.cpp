#include <iostream>
#include <cstdio>
#include <cstring>
#define NO "No!!!\n"
using namespace std;

int a,b,c,flag;
bool use[10];

inline void pd(int n1)
{
    if(n1*b%a!=0)return;
    if(n1*c%a!=0)return;
    int n2=n1*b/a,n3=n1*c/a;
    if(n2<123 || n2>987)return;
    if(n3<123 || n3>987)return;
    int vis[10]={0},n22=n2,n33=n3;
    vis[0]=1;
    vis[n1%10]=1;
    vis[n1/10%10]=1;
    vis[n1/100]=1;
    while(n22)
    {
        if(vis[n22%10])return;
        vis[n22%10]=1;
        n22/=10;
    }
    while(n33)
    {
        if(vis[n33%10])return;
        vis[n33%10]=1;
        n33/=10;
    }
    flag=1;
    printf("%d %d %d\n",n1,n2,n3);
}

void solve(int s,int n)
{
    if(s>3)
    {
        pd(n);
        return;
    }
    for(int i=1;i<=9;++i)
    {
        if(use[i]==0)
        {
            use[i]=1;
            solve(s+1,n*10+i);
            use[i]=0;
        }
    }
}

int main()
{
    scanf("%d%d%d",&a,&b,&c);
    solve(1,0);
    if(flag==0)
        printf(NO);
    return 0;
}
