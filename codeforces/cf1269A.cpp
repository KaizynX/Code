#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, k;
char s[N], ss[N];

inline bool check()
{
    for (int i = 1; i <= k && i <= n-k; ++i) {
        for (int j = i+k; j <= n; j += k)
            if (s[j] != s[i]) return false;
    }
    return true;
}

int main()
{
    scanf("%d %d %s", &n, &k, s+1);
    if (check()) return printf("%d\n%s\n", n, s+1)&0;
    strcpy(ss, s);
    for (int i = 1; i <= k && i <= n-k; ++i) {
        for (int j = i+k; j <= n; j += k)
            s[j] = s[i];
    }
    int tag = min(k, n-k), flag = 0;

    for (int i = tag+k; i <= n; ++i) {
        if (s[i] > s[tag]) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        ++s[tag];
        for (int i = n-k+1; i <= k; ++i)
            s[i] = '0';
    }
    for (int i = 1; i <= k && i <= n-k; ++i) {
        for (int j = i+k; j <= n; j += k)
            s[j] = s[i];
    }
    printf("%d\n%s\n", n, s+1);
    return 0;
}

