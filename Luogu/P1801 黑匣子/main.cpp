#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn=200000+5;
priority_queue <int ,vector<int>,greater<int > >q;
int m,n;
int add[maxn],get[maxn];

int main()
{
    int posm=1,cur;
    scanf("%d%d",&m,&n);
    for(int j=1;j<=m;++j)
    {
        scanf("%d",add+j);
    }
    for(int j=1;j<=n;++j)
    {
        scanf("%d",get+j);
    }
    for(int j=1;j<=m;++j)
    {
        q.push(add[j]);
        while(j==get[posm])
        {
            cur=q.top();
            q.pop();
            printf("%d\n",cur);
            posm++;
        }
        if(posm>n)break;
    }
    return 0;
}
