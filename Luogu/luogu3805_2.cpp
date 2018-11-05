#include <bits/stdc++.h>

using namespace std;

const int Maxn = 11000007;

char a[Maxn], b[Maxn<<1];
int c[Maxn<<1];

inline int manacher(const char *str, char *buf, int *p)
{
    int str_len = strlen(str), buf_len = 2;
    buf[0] = buf[1] = '#';
    for(int i = 0; i < str_len; ++i)
        buf[buf_len++] = str[i], buf[buf_len++] = '#';

    int mx = 0, id, ans = 0;
    for(int i = 1; i < buf_len; ++i)
    {
        if(i <= mx) p[i] = min(p[id*2-i], mx-i);
        else p[i] = 1;
        while(buf[i-p[i]] == buf[i+p[i]]) p[i]++;
        if(i+p[i] > mx) mx = i+p[i], id = i;
        ans = max(ans, p[i]-1);
    }
    return ans;
}

int main()
{
    gets(a);
    printf("%d\n", manacher(a, b, c));
    return 0;
}
