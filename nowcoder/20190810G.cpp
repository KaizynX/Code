#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

char str[Maxn], stac[Maxn];
int tail, res;

int main()
{
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < len; ++i)
    {
        if(tail >= 2 && str[i] == stac[tail-1] && str[i] == stac[tail-2])
        {
            tail -= 2;
            res++;
        }
        else stac[tail++] = str[i];
    }
    printf("%d\n", res);
    return 0;
}
