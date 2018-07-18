#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=200000+5;

inline int getint()
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

int main()
{
    int n,t,a,cur,ans;
    n=getint();
    t=getint();
    a=getint();
    ans=t;
    t--;
    cur=a+t;
    for(int i=2;i<=n;++i)
    {
        a=getint();
        if(a<=cur)
        {
            ans+=(a+t)-cur;
            cur=a+t;
        }
        else if(a>cur)
        {
            ans+=t+1;
            cur=a+t;
        }
    }
    printf("%d",ans);
    return 0;
}
