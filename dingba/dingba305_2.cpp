#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;

int n, q;
int a[N], add[N];
int sqr[N];

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", a+i);
    for (int i = 1, l, r; i <= q; ++i) {
        scanf("%d %d", &l, &r);
        ++add[l];
        --add[r+1];
    }
    for (int i = 1, now = 0; i <= n; ++i) {
        now += add[i];
        if (now >= 5) a[i] = 1;
        for (int j = 1; j <= now && a[i] > 1; ++j)
            a[i] = (int)sqrt(a[i]);
        printf("%d%c", a[i], " \n"[i==n]);
    }
    return 0;
}
