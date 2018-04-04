#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

priority_queue <int ,vector<int>,greater<int> >q;

int main()
{
    int n,a,b,s,x,y,i,ans=0;
    scanf("%d%d%d%d",&n,&s,&a,&b);
    b+=a;
    for(i=1;i<=n;++i)
    {
        scanf("%d%d",&x,&y);
        if(x<=b)
            q.push(y);
    }
    while(!q.empty())
    {
        y=q.top();
        q.pop();
        if(s>=y)
            s-=y;
        else break;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}
