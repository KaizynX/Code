#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e5+7;

int T, n;
int f[Maxn];

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        int b = 4, sp = 0;
        for(int i = 2; i <= n; ++i)
        {
            if(i == b-1)
            {
                if(b <= n) f[i] = b;
                else f[i] = 1, ++sp;
                b <<= 1;
            }
            int cur = 1, tmp = i;
            while(tmp)
            {
                if(!(tmp&1))
                {
                    f[i] = cur;
                    break;
                }
                tmp >>= 1;
                cur <<= 1;
            }
        }
        printf("%d\n", sp);
        for(int i = 2; i < n; ++i)
            printf("%d ", f[i]);
        printf("%d\n", f[n]);
    }
    return 0;
}
