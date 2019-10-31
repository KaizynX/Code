#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, res;
int a[N], b[N], f[N];

struct BinaryIndexedTree
{
    // set your type
    typedef int T;
    T tr[N];
    BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
    inline void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
    inline void update(int x, T v) { for ( ; x <= n; x += x&-x) tr[x] += v; }
    inline void update(int x, int y, T v) { update(x, v); update(y+1, -v); }
    inline T query(int x) { T res = 0; for ( ; x; x -= x&-x) res += tr[x]; return res; }
    inline T query(int x, int y) { return query(y)-query(x-1); }
} BIT;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        f[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        BIT.update(f[b[i]], 1);
        res += BIT.query(f[b[i]]) < f[b[i]];
    }
    cout << res << endl;
    return 0;
}
