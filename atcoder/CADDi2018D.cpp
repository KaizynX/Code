#include <bits/stdc++.h>

using namespace std;

int n, a;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        if(a&1) return puts("first")&0;
    }
    puts("second");
    return 0;
}
