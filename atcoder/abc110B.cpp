#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 110;
const int INF = 1e5;

int n, m, x, y;
int a = -INF, b = INF;

int main()
{
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for(int i = 1, tmp; i <= n; ++i)
    {
        scanf("%d", &tmp);
        a = max(tmp, a);
    }
    for(int i = 1, tmp; i <= m; ++i)
    {
        scanf("%d", &tmp);
        b = min(tmp, b);
    }
    // (x, y]
    // a < z, b >= z
    if(a < b && x < y && a < y && b > x) puts("No War");
    else puts("War");
    return 0;
}
