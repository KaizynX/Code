#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int Maxn = 1e6+7;

char str[Maxn];
int _next[Maxn], len;

inline void get_next()
{
    int i = 0, k = -1;
    len = strlen(str);
    _next[0] = -1;
    while(i < len)
    {
        if(k == -1 || str[i] == str[k])
            _next[++i] = ++k;
        else k = _next[k];
    }
}

int main()
{
    while(scanf("%s", str) && strcmp(str, "."))
    {
        get_next();
        printf("%d\n", len%(len- _next[len]) ? 1 : len/(len- _next[len]));
    }
    return 0;
}
