#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1e6+7;
const int Maxa = 1e4+7;

int T, n, t[Maxa];

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        memset(t, 0, sizeof t);
        scanf("%d", &n);
        int flag = 0, mina = Maxa, maxa = 0;
        for(int i = 1, a; i <= n; ++i)
        {
            scanf("%d", &a);
            if(++t[a] == 2)
            {
                mina = min(mina, a);
                maxa = max(maxa, a);
            }
            if(!flag && t[a] == 4)
            {
                flag = 1;
                printf("%d %d %d %d\n", a, a, a, a);
            }
        }
        if(flag) continue;
        int res1, res2;
        double resv = Maxn;
        for(int i = mina+1, last = mina; i <= maxa; ++i)
        {
            if(t[i] < 2) continue;
            if((double)i/last < resv)
            {
                resv = (double)i/last;
                res1 = last; res2 = i;
            }
            last = i;
        }
        printf("%d %d %d %d\n", res1, res1, res2, res2);
    }
    return 0;
}
