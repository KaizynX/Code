#include <bits/stdc++.h>

using namespace std;

const int Maxn = 100+7;
const int Maxa = 25000+7;

int T, n, m;
int a[Maxn];
bitset<Maxa> need, now;

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        m = 0;
        need.reset();
        now.reset();
        now.set(0);

        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", a+i);
            need.set(a[i]);
        }
        sort(a+1, a+n+1);
        for(int i = 1, j; i <= n; ++i)
        {
            if(!now[a[i]])
            {
                m++;
                for(j = 1; j*a[i] <= a[n]; j <<= 1)
                    now |= now<<(a[i]*j);
                j >>= 1;
                now |= now<<((a[n]-j*a[i])/a[i]*a[i]);
                if((now&need) == need) break;
            }
        }
        printf("%d\n", m);
    }
    return 0;
}
