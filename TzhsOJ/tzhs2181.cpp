#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int Maxn = 5e5+7;

int len, q, a, b;
int _next[Maxn];
char s[Maxn];

inline void read(int &x)
{
    char c;
    while((c=getchar()) < '0' || c > '9');
    x = c -'0';
    while((c=getchar()) >= '0' && c <= '9')
        x = (x<<1)+(x<<3) + c-'0';
}

inline void get_next()
{
    int i = 0, k = -1;
    _next[0] = -1;
    while(i < len)
    {
        if(k == -1 || s[i] == s[k])
            _next[++i] = ++k;
        else k = _next[k];
    }
}

int main()
{
    read(len);
    scanf("%s", s);
    read(q);
    get_next();
    while(q--)
    {
        read(a); read(b);
    }
    return 0;
}
