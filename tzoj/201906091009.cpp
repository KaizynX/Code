#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e5+7;

int T, n;
int a[Maxn], f[17];

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        int flag = 0;
        char c;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
        {
            cin >> c;
            a[i] = c-'0';
        }
        for(int i = 1; i <= 9; ++i) scanf("%d", f+i);
        for(int i = 1; i <= n; ++i)
        {
            if(f[a[i]] > a[i])
            {
                flag = 1;
                a[i] = f[a[i]];
            }
            else if(f[a[i]] < a[i] && flag) break;
        }
        for(int i = 1; i <= n; ++i) printf("%d", a[i]);
        putchar('\n');
    }
    return 0;
}
