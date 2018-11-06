#include <bits/stdc++.h>

using namespace std;

const int MOD = 19260817;

int a, b;

inline void read(int &x)
{
    char c;
    while(!isdigit((c=getchar())));
    x = c-'0';
    while(isdigit((c=getchar())))
        x = (x*10+c-'0')%MOD;
}

void exgcd(int a, int b, int &x, int &y)
{
    if(!b) { x = 1; y = 0; return; }
    exgcd(b, a%b, y, x);
    y -= a/b*x;
}

inline int mul_inverse(int n)
{
    int x, y;
    exgcd(n, MOD, x, y);
    return (x%MOD+MOD)%MOD;
}

int main()
{
    read(a); read(b);
    if(!b) puts("Angry!");
    else printf("%d\n", (int)(1ll*a*mul_inverse(b)%MOD));
    return 0;
}
