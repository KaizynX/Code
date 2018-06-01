#include <iostream>
#include <cstdio>
#include <cmath>
/**WA -10 TLE -10  AC 80 **/
using namespace std;
const int maxn =15+5;
const int INF=100000086;
struct node
{
    int x,y;
}s[maxn];
int n;
double ans=INF;
double d[maxn][maxn];
bool use[maxn];

inline void in();
inline void init();

void dfs(int last,int cur,double t)
{
    if(cur>n)
    {
        if(t<ans)
            ans=t;
        return;
    }
    if(t>=ans)
        return;
    for(int i=1;i<=n;++i)
    {
        if(use[i]==0)
        {
            use[i]=1;
            dfs(i,cur+1,t+d[last][i]);
            use[i]=0;
        }
    }
}

int main()
{
    in();
    init();
    dfs(0,1,0);
    printf("%.2f\n",ans);
    return 0;
}

inline void in()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&s[i].x,&s[i].y);
    }
}

inline void init()
{
    int x1,x2,y1,y2;
    double dis;
    s[0].x=0;
    s[0].y=0;
    for(int i=0;i<=n;++i)
    {
        x1=s[i].x;
        y1=s[i].y;
        for(int j=i+1;j<=n;++j)
        {
            if(i==j)continue;
            x2=s[j].x;
            y2=s[j].y;
            dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
            d[i][j]=dis;
            d[j][i]=dis;
        }
    }
}
