#include <bits/stdc++.h>

using namespace std;

const int N = 5e4+7;
const int K = 11;

template <typename T>
struct BinaryIndexedTree
{
    int n;
    T tr[N];
    BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
    void init(const int &_n) { n = _n; clear(); }
    void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
    void add(const int &x, const T &v) { for (int i = x ; i <= n; i += i&-i) tr[i] += v; }
    void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
    T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
    T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

int a[N];
BinaryIndexedTree<int> BIT[K][K];

int main()
{
    int n, q, op, x, y, z, k;
    while (scanf("%d", &n) == 1) {
        for (int i = 1; i <= 10; ++i)
            for (int j = 0; j < i; ++j)
                BIT[i][j].init(n);
        for (int i = 1; i <= n; ++i) scanf("%d", a+i);
        scanf("%d", &q);
        while (q--) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d %d %d %d", &x, &y, &k, &z);
                BIT[k][x%k].add(x, z);
                BIT[k][x%k].add(y+1, -z);
            } else if (op == 2) {
                scanf("%d", &x);
                int res = a[x];
                for (k = 1; k <= 10; ++k)
                    res += BIT[k][x%k].query(x);
                printf("%d\n", res);
            }
        }
    }
    return 0;
}
