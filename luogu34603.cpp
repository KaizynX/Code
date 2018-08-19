#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int Maxn = 2e3+7;

int n, m, K;
struct Line
{
    int k, b;
    long long y;
    inline void calc(int x)
    {
        y = (long long)k*x+b;
    }
} a[Maxn];

template <typename T> inline void read(T &x)
{
    char c; T tag = 1;
    while((c=getchar()) < '0' || c > '9') if(c == '-') tag = -1;
    x = c-'0';
    while((c=getchar()) >= '0' && c <= '9') x = (x<<1)+(x<<3) + c-'0';
    x *= tag;
}

template <typename T> void put(T x)
{
    if(x < 0)
    {
        putchar('-');
        x = -x;
    }
    if(x/10) put(x/10);
    putchar(x%10+'0');
}

long long find_kth(int l, int r)
{
    if(l == r) return a[l].y;
    swap(a[l].y, a[l+rand()%(r-l)].y);
    long long mid = a[l].y;
    int i = l, j = r;
    while(i < j)
    {
        while(i < j && a[j].y >= mid) --j;
        a[i].y = a[j].y;
        while(i < j && a[i].y < mid) ++i;
        a[j].y = a[i].y;
    }
    a[i].y = mid;
#ifdef DEBUG
    printf("\n%d %d %d\n", l, r, i);
    for(int i = 1; i <= n; ++i)
    {
        printf("%d ", a[i].y);
    }
    putchar('\n');
#endif
    if(i == K) return mid;
    else if(i > K) return find_kth(1, i-1);
    else return find_kth(i+1, r);
}

int main()
{
    read(n); read(m); read(K);
    for(int i = 1; i <= n; ++i)
        read(a[i].k), read(a[i].b);
    int x;
    while(m--)
    {
        read(x);
        for(int i = 1; i <= n; ++i) a[i].calc(x);
        put(find_kth(1, n));
        putchar('\n');
    }
    return 0;
}
