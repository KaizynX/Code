#include <iostream>
#include <cstdio>

using namespace std;

int r, n, ans = 1;

struct Node
{
    int num, cnt;
} a[1000000];

inline int fx(int x)
{
    if(x%2 == 0) return 0;
    else if((x-1)%4 == 0) return 1;
    else if((x+1)%4 == 0) return -1;
}

inline int quickm(int k, int p)
{
    int res = 1;
    while(p)
    {
        if(p&1) res *= k;
        p >>= 1;
        k *= k;
    }
    return res;
}

int main()
{
    scanf("%d", &r);
    for(int i = 2; r > 1; ++i)
    {
        if(r % i == 0) a[++n].num = i;
        while(r % i == 0)
        {
            ++a[n].cnt;
            r /= i;
        }
    }

    for(int i = 1, tmp; i <= n; ++i)
    {
        a[i].cnt <<= 1;
        tmp = 0;
        for(int j = 0; j <= a[i].cnt; ++j)
            tmp += fx(quickm(a[i].num, j));
        ans *= tmp;
    }
    cout << ans * 4 << endl;
    return 0;
}
