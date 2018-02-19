#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
const int maxn=10000+5;
priority_queue <int ,vector<int>,greater<int> > q;

int read()
{
    char c;
    int res=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

int main()
{
    int i,a,b,n;
    long long ans=0;
    n=read();
    for(i=1;i<=n;++i)
    {
        a=read();
        q.push(a);
    }
    for(i=1;i<n;++i)
    {
        a=q.top();
        q.pop();
        b=q.top();
        q.pop();
        ans+=a+b;
        q.push(a+b);
    }
    printf("%lld\n",ans);
    return 0;
}
