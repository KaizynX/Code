#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T, d, h, f, n, x, y;


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

inline double calc(int d, int h, int f) {
    return 1.0*d*h/(h+f);
}

inline bool cmp(int i, int j) {
    // (d+i*x)*(h+(n-i)*y)/(h+(n-i)*y+f)
    return 1ll*(d+i*x)*(h+(n-i)*y)*(h+(n-j)*y+f) < 1ll*(d+j*x)*(h+(n-j)*y)*(h+(n-i)*y+f);
}

int main()
{
    read(T);
    while (T--) {
        read(d);
        read(h);
        read(f);
        read(n);
        read(x);
        read(y);
        int res = 0;
        for (int i = 1; i <= n; ++i)
            if (cmp(res, i)) res = i;
        write(res);
        putchar(' ');
        write(n-res);
        putchar('\n');
    }
    return 0;
}
