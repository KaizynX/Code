#include<iostream>
#include<cstdio>
using namespace std;
int n,a[10],u[10];
void f(int t)
{
    if(t==n)
    {
        for(int i=1;i<=n;++i)
            printf("%5d",a[i]);
        printf("\n");
        return;
    }
    for(int i=1;i<=n;++i)
    {
        if(!u[i])
        {
            u[i]=1;
            a[t+1]=i;
            f(t+1);
            u[i]=0;
        }
    }
}
int main()
{
    cin>>n;
    f(0);
    return 0;
}
