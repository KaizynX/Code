#include <cstdio>
#include <iostream>

using namespace std;

long long n, q, x, y, pos;

int main()
{
    scanf("%I64d%I64d", &n, &q);
    while(q--)
    {
        scanf("%I64d%I64d", &x, &y);
        pos = n*(x-1)+y;
        if(n&1)
        {
            if(pos&1) printf("%I64d\n", (pos+1)/2);
            else printf("%I64d\n", n*n/2+pos/2+1);
        }
        else
        {
            if(x&1)
            {
                if(pos&1) printf("%I64d\n", (pos+1)/2);
                else printf("%I64d\n", n*n/2+pos/2);
            }
            else
            {
                if(pos&1) printf("%I64d\n", n*n/2+(pos+1)/2);
                else printf("%I64d\n", pos/2);
            }
        }
    }
    return 0;
}
