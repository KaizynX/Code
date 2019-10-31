#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 1e5+7;

int n, m, p;

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

struct FenKuai
{
    typedef long long T;
    int t, sz;
    static const int NN = static_cast<int>(sqrt(N))+7;
    T a[N], sum[NN], tag_add[NN], tag_mul[NN];

    void init(int _n)
    {
        sz = _n;
        t = static_cast<int>(sqrt(sz)+0.5);
        for (int i = 0; i < sz; ++i) {
            a[i] %= p;
            if (i%t == 0) sum[i/t] = 0;
            (sum[i/t]+=a[i])%=p;
            tag_add[i/t] = 0;
            tag_mul[i/t] = 1;
        }
    }

    void modify(int x)
    {
        if (tag_add[x] == 0 && tag_mul[x] == 1) return;
        for (int i = x*t; i < min(x*t+t, sz); ++i) a[i] = (a[i]*tag_mul[x]+tag_add[x])%p;
        tag_add[x] = 0; tag_mul[x] = 1;
    }

    void add(int x, int y, T k)
    {
        int i = x;
        modify(x/t); for ( ; i <= y && i%t; ++i) (a[i]+=k)%=p, (sum[i/t]+=k)%=p;
        for ( ; i+t-1 <= y; i += t) (tag_add[i/t]+=k)%=p, (sum[i/t]+=k*t)%=p;
        modify(y/t); for ( ; i <= y; ++i) (a[i]+=k)%=p, (sum[i/t]+=k)%=p;
    }

    void mul(int x, int y, T k)
    {
        int i = x;
        modify(x/t); for ( ; i <= y && i%t; ++i) (sum[i/t]+=a[i]*(k-1))%=p, (a[i]*=k)%=p;
        for ( ; i+t-1 <= y; i += t) (tag_mul[i/t]*=k)%=p, (tag_add[i/t]*=k)%=p, (sum[i/t]*=k)%=p;
        modify(y/t); for ( ; i <= y; ++i) (sum[i/t]+=a[i]*(k-1))%=p, (a[i]*=k)%=p;
    }

    T query(int x) { return (a[x]*tag_mul[x/t]+tag_add[x/t])%p; }
    T query(int x, int y)
    {
        T res = 0;
        int i  = x;
        for ( ; i <= y && i%t; ++i) (res += a[i]*tag_mul[i/t]+tag_add[i/t])%=p;
        for ( ; i+t-1 <= y; i += t) (res+=sum[i/t])%=p;
        for ( ; i <= y; ++i) (res += a[i]*tag_mul[i/t]+tag_add[i/t])%=p;
        return res;
    }
} B;

int main()
{
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 0; i < n; ++i) read(B.a[i]);
    B.init(n);
    for (int i = 0, op, x, y; i < m; ++i) {
        read(op); read(x); read(y);
        --x; --y;
        if (op == 3) {
            write(B.query(x, y));
            putchar('\n');
            continue;
        }
        long long k;
        read(k);
        if (op == 1) {
            B.mul(x, y, k%p);
        } else {
            B.add(x, y, k%p);
        }
#ifdef DEBUG
        for (int i = 0; i < n; ++i)
            write(B.query(i)), putchar(" \n"[i==n-1]);
#endif
    }
    return 0;
}
