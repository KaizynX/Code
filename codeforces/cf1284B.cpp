#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e6+7;

int n;
int maxv[N], minv[N], flag[N];
long long res;

struct BinaryIndexedTree
{
    // set your type
    static const int sz = 1e6+5;
    typedef int T;
    T tr[N];
    BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
    inline void clear() { for (int i = 1; i <= sz; ++i) tr[i] = 0; }
    inline void update(int x, T v) { for ( ; x <= sz; x += x&-x) tr[x] += v; }
    inline void update(int x, int y, T v) { update(x, v); update(y+1, -v); }
    inline T query(int x) { T res = 0; for ( ; x; x -= x&-x) res += tr[x]; return res; }
    inline T query(int x, int y) { return query(y)-query(x-1); }
} BIT;

int main()
{
    scanf("%d", &n);
    for (int i = 1, a, l; i <= n; ++i) {
        scanf("%d%d", &l, &a);
        a += 2;
        maxv[i] = minv[i] = a;
        for (int j = 1; j < l; ++j) {
            scanf("%d", &a);
            a += 2;
            if (a > minv[i]) flag[i] = 1;
            maxv[i] = max(a, maxv[i]);
            minv[i] = min(a, minv[i]);
        }
        if (flag[i]) BIT.update(1, 1);
        else BIT.update(minv[i], 1);
    }
    for (int i = 1; i <= n; ++i) {
        if (flag[i]) {
            res += n;
        } else {
            res += BIT.query(maxv[i]-1);
        }
#ifdef DEBUG
            cout << BIT.query(maxv[i]-1) << " ";
#endif
    }
    cout << res << endl;
    return 0;
}
