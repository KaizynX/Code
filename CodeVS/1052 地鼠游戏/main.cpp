#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=105;
struct mouse
{
    int t,v;
}m[maxn];
int n;
bool cmp(mouse a,mouse b)
{
    return a.t>b.t;
}
priority_queue <int> q;
int main()
{
    int i,cur=1,now,ans=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>m[i].t;
    for(i=1;i<=n;++i)
        cin>>m[i].v;
    sort(m+1,m+n+1,cmp);
    now=m[1].t;
    while(now)
    {
        while(m[cur].t==now)
        {
            q.push(m[cur].v);
            cur++;
        }
        if(!q.empty())
        {
            ans+=q.top();
            q.pop();
        }
        now--;
    }
    cout<<ans<<endl;
    return 0;
}
