#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e5+7;

int n, T, m;
int tr[Maxn], ok[Maxn];
long long a[Maxn];

template <typename T> inline void read(T &x)
{
    char c;
    while(!isdigit((c=getchar())));
    x = c-'0';
    while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
}

template <typename T> void write(T x)
{
    if(x > 9) write(x/10);
    putchar(x%10+'0');
}

inline void update_tree(int i, int x)
{
    for( ; i <= n; i += i&-i) tr[i] += x;
}

inline int query_tree(int x, int y)
{
    int resx = 0, resy = 0;
    for(int i = x-1; i; i -= i&-i) resx += tr[i];
    for(int i = y; i; i -= i&-i) resy += tr[i];
    return resy-resx;
}

int main()
{
    read(n); read(T);
    for(int i = 1; i <= n; ++i)
    {
        read(a[i]);
        if(a[i] <= T) ok[i] = 1, update_tree(i, 1);
        else ok[i] = -1;
    }
    read(m);
    string str;
    int x, y, now;
    while(m--)
    {
        cin >> str;
        read(x); read(y);
        if(str == "Zero")
            write(600ll*query_tree(x, y)), putchar('\n');
        else
        {
            if(str == "BookCity")
                a[x] = max(a[x]-y, 1ll);
            else if(str == "Guy")
                a[x] *= y;
            else if(str == "tingtime")
                a[x] = y;
            now = a[x] <= T ? 1 : -1;
            if(ok[x] != now) update_tree(x, (ok[x]=now));
        }
    }
    return 0;
}
