#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n, ans;
int a[Maxn];
int stk[Maxn], sz;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", a+i);
    stk[++sz] = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(a[i] > stk[sz])
        {
            ans += a[i]-stk[sz];
            stk[++sz] = a[i];
        }
        else
        {
            while(sz && stk[sz] >= a[i]) sz--;
            stk[++sz] = a[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
