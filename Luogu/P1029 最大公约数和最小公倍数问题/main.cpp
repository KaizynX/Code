#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=100000+5;

int x0,y0,ans;

int f(int a,int b)
{
    /**
    int tmp;
    if(a<b)swap(a,b);
    while(b)
    {
        tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
    **/
    if(b==0)return a;
    if(a<b)swap(a,b);
    return f(b,a%b);
}

int main()
{
    scanf("%d%d",&x0,&y0);
    int i,j;
    for(i=x0;i<=y0;i+=x0)
    {
        //i*j/x0=y0;
        if(x0*y0%i!=0)
            continue;
        j=x0*y0/i;
        if(j%x0!=0)
            continue;
        if(f(i,j)==x0)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}
