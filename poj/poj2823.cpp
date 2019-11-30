#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6+7;

int n, k, hb, tb, hs, ts;
int b[N], s[N];
pair<int, int> qb[N], qs[N];

int main()
{
    while (scanf("%d %d", &n, &k) == 2) {
        hb = tb = hs = ts = 0;
        for (int i = 0, a; i < n; ++i) {
            scanf("%d", &a);
            while (hb < tb && qb[tb].first <= a) --tb;
            while (hb < tb && qb[hb+1].second <= i-k) ++hb;
            qb[++tb] = {a, i};
            b[i] = qb[hb+1].first;
            while (hs < ts && qs[ts].first >= a) --ts;
            while (hs < ts && qs[hs+1].second <= i-k) ++hs;
            qs[++ts] = {a, i};
            s[i] = qs[hs+1].first;
        }
        for (int i = k-1; i < n; ++i)
            printf("%d%c", s[i], " \n"[i==n-1]);
        for (int i = k-1; i < n; ++i)
            printf("%d%c", b[i], " \n"[i==n-1]);
    }
    return 0;
}
