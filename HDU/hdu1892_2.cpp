#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

template <typename T>
struct BIT_2D
{
    int n, m;
    T a[N][N], tr[N][N];
    BIT_2D() { memset(tr, 0, sizeof tr); }
    void init(const int &_n, const int &_m) {
        n = _n; m = _m;
        memset(a, 0, sizeof a);
        memset(tr, 0, sizeof tr);
    }
    void add(const int &x, const int &y, const T &k) {
        a[x][y] += k;
        for (int i = x; i <= n; i += i&-i)
            for (int j = y; j <= m; j += j&-j)
                tr[i][j] += k;
    }
    T query(const int &x, const int &y) {
        return a[x][y];
        // return query(x, y, x, y);
    }
    T query(const int &r1, const int &c1, const int &r2, const int &c2) {
        return _query(r2, c2)-_query(r1-1, c2)-_query(r2, c1-1)+_query(r1-1, c1-1);
    }
    T _query(const int &x, const int &y) {
        T res = 0;
        for (int i = x; i; i -= i&-i)
            for (int j = y; j; j -= j&-j)
                res += tr[i][j];
        return res;
    }
};
BIT_2D<int> BIT;

inline void solve()
{
    char op;
    int q, r1, c1, r2, c2, k;
    BIT.init(1003, 1003);
    for (int i = 1; i <= 1003; ++i)
        for (int j = 1; j <= 1003; ++j)
            BIT.add(i, j, 1);
    scanf("%d", &q);
    while (q--) {
        getchar();
        scanf("%c", &op);
        switch (op) {
            case 'S' :
                scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
                ++r1; ++c1; ++r2; ++c2;
                if (r1 > r2) swap(r1, r2);
                if (c1 > c2) swap(c1, c2);
                printf("%d\n", BIT.query(r1, c1, r2, c2));
                break;
            case 'A' :
                scanf("%d %d %d", &r1, &c1, &k);
                ++r1; ++c1;
                BIT.add(r1, c1, k);
                break;
            case 'D' :
                scanf("%d %d %d", &r1, &c1, &k);
                ++r1; ++c1;
                BIT.add(r1, c1, -min(BIT.query(r1, c1), k));
                break;
            case 'M' :
                scanf("%d %d %d %d %d", &r1, &c1, &r2, &c2, &k);
                ++r1; ++c1; ++r2; ++c2;
                k = min(BIT.query(r1, c1), k);
                BIT.add(r1, c1, -k);
                BIT.add(r2, c2, k);
                break;
            default :
                break;
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case %d:\n", i);
        solve();
    }
    return 0;
}
