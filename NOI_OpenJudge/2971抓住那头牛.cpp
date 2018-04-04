#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=100000;
const int maxq=1000000;

int n,k,head,tail;
int q[maxq],t[maxq];
bool vis[maxn+5];

void bfs()
{
    int a,b,nex;
    tail++;
    q[tail]=n;
    t[tail]=0;
    vis[n]=1;
    while(head<tail)
    {
        head++;
        a=q[head];
        b=t[head];
        if(a==k)
        {
            printf("%d\n",b);
            return;
        }
        nex=a+1;
        if(vis[nex]==0 && nex>=0 && nex<=maxn)
        {
            vis[nex]=1;
            tail++;
            q[tail]=nex;
            t[tail]=b+1;
        }
        nex=a-1;
        if(vis[nex]==0 && nex>=0 && nex<=maxn)
        {
            vis[nex]=1;
            tail++;
            q[tail]=nex;
            t[tail]=b+1;
        }
        nex=a*2;
        if(vis[nex]==0 && nex>=0 && nex<=maxn)
        {
            vis[nex]=1;
            tail++;
            q[tail]=nex;
            t[tail]=b+1;
        }
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    bfs();
    return 0;
}
