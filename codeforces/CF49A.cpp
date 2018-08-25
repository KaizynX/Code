#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 110;

int T, n, flag;
char str[Maxn];

inline int abs(int x)
{
    return x < 0 ? -x : x;
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        flag = 1;
        scanf("%d", &n);
        scanf("%s", str+1);
        for(int i = 1, j; i <= n/2; ++i)
        {
            j = n-i+1;
            if(str[i] != str[j] && abs(str[i]-str[j]) != 2)
            {
                flag = 0;
                puts("NO");
                break;
            }
        }
        if(flag) puts("YES");
    }
    return 0;
}
