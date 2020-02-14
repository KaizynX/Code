#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int n, ans;
char s[N], ss[N];

inline int calc(int x)
{
    int res = 0;
    while (x) {
        res += x&1;
        x >>= 1;
    }
    return res;
}

inline void rev(int p)
{
    for (int i = p-1; i <= p+1; ++i)
        if (i >= 0 && i < n)
            ss[i] ^= 1;
}

inline void f(int x)
{
    for (int i = 0; i < n; ++i)
        ss[i] = s[i];
    for (int i = 0; i < n; ++i)
        if ((x>>i)&1) rev(i);
    for (int i = 0; i < n; ++i)
        if (ss[i] == 1) return;
    ans = min(ans, calc(x));
}

int main()
{
    while (scanf("%s", s) != EOF) {
        n = strlen(s);
        ans = n+1;
        for (int i = 0; i < n; ++i) s[i] -= '0';
        for (int i = 0; i < 1<<n; ++i) f(i);
        if (ans > n) puts("NO");
        else printf("%d\n", ans);
    }
    return 0;
}
