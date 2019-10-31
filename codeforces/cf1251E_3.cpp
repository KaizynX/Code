#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, t;
long long res;

struct Node
{
    int m, p;
} a[N];

bool cmpp(const Node &x, const Node &y) { return x.p == y.p ? x.m > y.m : x.p < y.p; }
bool cmpm(const Node &x, const Node &y) { return x.m == y.m ? x.p > y.p : x.m < y.m; }

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &a[i].m, &a[i].p);
        }
        sort(a+1, a+n+1, cmpm);
        int cnt = 0, st = 0, cur = 0, pos = 1;
        while (cur < n) {
            while (pos <= n && a[pos].m <= cur) {
                if (!st) st = pos;
                ++cur;
                ++pos;
            }
            if (cur >= n) break;
            ++cur;
            ++cnt;
            st = 0;
        }
        sort(a+st, a+n+1, cmpp);
        for (int i = 0; i < cnt; ++i) {
            res += a[st+i].p;
        }
        printf("%I64d\n", res);
    }
    return 0;
}
