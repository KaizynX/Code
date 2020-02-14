#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;
const double err = 1e-1;

int n, q;
int a[N], add[N];
int pow2[30], sqr[N];

template <typename T> inline void read(T &x)
{
    char c; T tag = 1;
    while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
    x = c-'0';
    while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
    x *= tag;
}

template <typename T> void write(T x)
{
    if(x < 0) x = -x, putchar('-');
    if(x > 9) write(x/10);
    putchar(x%10+'0');
}

int main()
{
    pow2[0] = 1;
    for (int i = 1; i < 30; ++i) pow2[i] = pow2[i-1]<<1; 
    for (int i = 1; i <= 1000; ++i) sqr[i*i] = i;
    for (int i = 1; i <= 1000000; ++i) if (!sqr[i]) sqr[i] = sqr[i-1];
    read(n); read(q);
    for (int i = 1; i <= n; ++i) read(a[i]);
    for (int i = 1, l, r; i <= q; ++i) {
        read(l); read(r);
        ++add[l];
        --add[r+1];
    }
    for (int i = 1, now = 0; i <= n; ++i) {
        now += add[i];
        if (now >= 5 || a[i] < pow2[pow2[now]]) a[i] = 1;
        for (int j = 1; j <= now && a[i] > 1; ++j)
            a[i] = sqr[a[i]];
        write(a[i]);
        putchar(" \n"[i==n]);
    }
    return 0;
}
