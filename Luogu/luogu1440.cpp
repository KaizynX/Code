#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 2e6+7;

int n, m;
int head, tail;
pair<int, int> q[Maxn];

template <typename T> inline void read(T &x)
{
    char c;
    while((c=getchar()) < '0' || c > '9');
    x = c-'0';
    while((c=getchar()) >= '0' && c <= '9')
        x = (x<<1)+(x<<3) + c-'0';
}

template <typename T> inline void put(T x)
{
    if(x == 0)return;
    put(x/10);
    putchar(x%10+'0');
}

int main()
{
    int a;
    read(n); read(m); read(a);
    q[0] = make_pair(a, 1);
    puts("0");
    for(int i = 2, a; i <= n; ++i)
    {
        read(a);
        while(head <= tail && q[head].second < i-m) head++;
        put(q[head].first); putchar('\n');
        while(head <= tail && q[tail].first >= a) tail--;
        q[++tail] = make_pair(a, i);
    }
    return 0;
}
