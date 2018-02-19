#include <iostream>
#include <cstdio>
using namespace std;
const double PI = 3.14159 ;
const int Maxn = 1000 + 5 ;

int T , N , x , y ;
char c;
double ans,now;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        ans=0;
        while(N--)
        {
            cin>>c;
            if(c=='C')
            {
                scanf("%d",&x);
                now=x*x*PI;
                if(now>ans)ans=now;
            }
            else if(c=='T')
            {
                scanf("%d%d",&x,&y);
                now=x*y/2;
                if(now>ans)ans=now;
            }
            else if(c=='R')
            {
                scanf("%d%d",&x,&y);
                now=x*y;
                if(now>ans)ans=now;
            }
        }
        if(N!=0)
            printf("%.2f\n",ans);
        else
            printf("%.2f",ans);
    }
    return 0;
}
