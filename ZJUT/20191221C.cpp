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
        double mv = calc(d, h+n*y, f), tmp;
        for (int i = 1; i <= n; ++i) {
            if ((tmp = calc(d+i*h, h+(n-i)*y, f)) > mv) {
                mv = tmp;
                res = i;
            }
        }
        write(res);
        putchar(' ');
        write(n-res);
        putchar('\n');
    }
    return 0;
}
