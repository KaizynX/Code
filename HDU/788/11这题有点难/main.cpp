#include <iostream>
#include <cstdio>
#define Y "Yes\n"
#define N "No\n"
using namespace std;

const int Maxt = 20+5;
const int Maxa = 100+5;
const int Maxq = 10000+5;
const int Maxc = 100+5;

int T,a,b,c,q;

int main()
{
    int d;
    scanf("%d",&T);
    while(T--)
    {
        // x*a == c + y*b
        scanf("%d%d%d",&a,&b,&q);
        while(q--)
        {
            scanf("%d",&c);
            if(a==b)
            {
                if(c%a==0 || c==0)
                    printf(Y);
                else
                    printf(N);
            }
            else if(c==0)
            {
                if(b%a==0 || a%b==0)
                    printf(Y);
                else
                    printf(N);
            }
            else
            {
                ;
            }
        }
    }
    return 0;
}
