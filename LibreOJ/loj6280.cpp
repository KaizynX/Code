#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n;

struct FenKuai
{
    typedef long long T;
    int t; // ÿ���С
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
        for (int i = 0; i < n; ++i) sum[i/t] += a[i];
    }

    void update(int x, T k) { a[x] += k; sum[x/t] += k; }
    void update(int x, int y, T k)
    {
        for ( ; x <= y && x%t; ++x) a[x] += k, sum[x/t] += k;
        for ( ; x+t-1 <= y; x += t) sum[x/t] += k*t, add[x/t] += k;
        for ( ; x <= y; ++x) a[x] += k, sum[x/t] += k;
    }

    T query(int x) { return a[x]+add[x/t]; }
    T query(int x, int y)
    {
        T res = 0;
        for ( ; x <= y && x%t; ++x) res += a[x]+add[x/t];
        for ( ; x+t-1 <= y; x += t) res += sum[x/t];
        for ( ; x <= y; ++x) res += a[x]+add[x/t];
        return res;
    }
} B;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lld", &B.a[i]);
    B.init();
    for (int i = 0, op, l, r, c; i < n; ++i) {
        scanf("%d %d %d %d", &op, &l, &r, &c);
        --l; --r;
        if (op) {
            printf("%d\n", static_cast<int>(B.query(l, r)%(c+1)));
        } else {
            B.update(l, r, c);
        }
    }
    return 0;
}
