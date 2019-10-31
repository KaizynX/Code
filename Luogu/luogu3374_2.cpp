#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+7;

int n, m;

struct FenKuai
{
    typedef long long T;
    int t; // 每组大小
    static const int NN = static_cast<int>(sqrt(N))+7;
    T a[N], sum[NN], add[NN];

    FenKuai()
    {
        memset(a, 0, sizeof a);
        memset(sum, 0, sizeof sum);
        memset(add, 0, sizeof add);
    }

    void init()
    {
        t = static_cast<int>(sqrt(n)+0.5);
        for (int i = 0; i < n; ++i) {
            sum[i/t] += a[i];
        }
    }

    void update(int x, T k) { a[x] += k; sum[x/t] += k; }
    void update(int x, int y, T k)
    {
        if (x/t == y/t) {
            for (int i = x; i <= y; ++i)
                a[i] += k;
            return;
        }

        while (x < n && x%t) {
            a[x] += k;
            sum[x/t] += k;
            ++x;
        }
        while (y >= 0 && y%t != t-1) {
            a[y] += k;
            sum[y/t] += k;
            --y;
        }
        for (int i = x/t; i <= y/t; ++i) {
            add[i] += k;
            sum[i] += k*t;
        }
    }

    T query(int x) { return a[x]+add[x/t]; }
    T query(int x, int y)
    {
        T res = 0;
        if (x/t == y/t) {
            for (int i = x; i <= y; ++i)
                res += a[i]+add[i/t];
            return res;
        }

        while (x < n && x%t) {
            res += a[x]+add[x/t];
            ++x;
        }
        while (y >= 0 && y%t != t-1) {
            res += a[y]+add[y/t];
            --y;
        }
        for (int i = x/t; i <= y/t; ++i) {
            res += sum[i];
        }
        return res;
    }
} B;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &B.a[i]);
    B.init();
    for (int i = 0, op, x, y; i < m; ++i) {
        scanf("%d %d", &op, &x);
        if (op == 1) {
            long long k;
            scanf("%lld", &k);
            B.update(x-1, k);
        } else {
            scanf("%d", &y);
            printf("%lld\n", B.query(x-1, y-1));
        }
    }
    return 0;
}
