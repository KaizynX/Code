#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, m;

struct FenKuai
{
    typedef int T;
    int t; // 每组大小
    T a[N], b[N], add[N];

    FenKuai()
    {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(add, 0, sizeof add);
    }

    void build(int x)
    {
        for (int i = x*t; i < min(x*t+t, n); ++i) b[i] = a[i];
        sort(b+x*t, b+min(x*t+t, n));
    }

    void init()
    {
        t = static_cast<int>(sqrt(n)+0.5);
        for (int i = 0; i*t < n; ++i) build(i);
    }

    void update(int x, int y, T c)
    {
        int i = x;
        for ( ; i <= y && i%t; ++i) a[i] += c;
        build(x/t);
        for ( ; i+t-1 <= y; i += t) add[i/t] += c;
        for ( ; i <= y; ++i) a[i] += c;
        build(y/t);
    }

    T query(int x, int y, T c)
    {
        T res = -1; int i = x;
        for ( ; i <= y && i%t; ++i) if (a[i]+add[i/t] < c) res = max(res, a[i]+add[i/t]);
        for ( ; i+t-1 <= y; i += t) {
            int p = lower_bound(b+i, b+i+t, c-add[i/t])-b-1;
            if (p >= i && b[p]+add[p/t] < c) res = max(res, b[p]+add[p/t]);
        }
        for ( ; i <= y; ++i) if (a[i]+add[i/t] < c) res = max(res, a[i]+add[i/t]);
        return res;
    }
} B;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &B.a[i]);
    }
    B.init();
    for (int i = 0, op, x, y, c; i < n; ++i) {
        scanf("%d %d %d %d", &op, &x, &y, &c);
        if (!op) {
            B.update(x-1, y-1, c);
        } else {
            printf("%d\n", B.query(x-1, y-1, c));
        }
    }
    return 0;
}
