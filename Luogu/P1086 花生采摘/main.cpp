#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#define exit printf("%d\n",ans);return 0;
#define emptyq if(q.empty()){exit;}
using namespace std;
const int maxn = 20+5;
const int maxk=1000+5;

int n,m,k,ans,nx,ny,rest,next,pick;
int a[maxn][maxn];
struct peanut
{
    int x,y,v;
    bool operator < (const peanut b)const
    {
        return v<b.v;
    }
}p;
priority_queue < peanut > q;

inline void in();
inline void q_out();
inline int cul();

int main()
{
    in();
    emptyq;
    //first
    rest=k;
    q_out();
    nx=p.x;ny=p.y;
    if(p.x*2+1>rest)
    {
        exit;
    }
    else
    {
        rest-=p.x+1;
        ans+=p.v;
    }
    emptyq;
    q_out();
    pick=cul();
    next=pick+p.x;
    while(rest>=next)
    {
        rest-=pick;
        ans+=p.v;

        nx=p.x;ny=p.y;
        emptyq;
        q_out();
        pick=cul();
        next=pick+p.x;
    }
    exit;
    return 0;
}

inline void in()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j])
            {
                p.x=i;
                p.y=j;
                p.v=a[i][j];
                q.push(p);
            }
        }
    }
}

inline void q_out()
{
    p=q.top();
    q.pop();
}

inline int cul()
{
    return abs(nx-p.x)+abs(ny-p.y)+1;
}
