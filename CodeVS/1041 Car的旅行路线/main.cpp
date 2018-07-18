#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxs=100+5;
int N,S,T,A,B;
struct Point
{
    int x,y;
}p[maxs*4];
int main()
{
    int i,j,t,now;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d%d%d",&S,&T,&A,&B);
        for(i=1;i<=S;++i)
        {
            for(j=1;j<=4;++j)
            {
                now=i*4-4+j;
                scanf("%d%d",&p[now].x,&p[now].y);
            }
            scanf("%d",&t);
        }
    }
    return 0;
}
