#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, res;
int a[N], dp[N];

struct BinaryIndexedTree
{
    typedef int T;
    T tr[N];
    BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
    inline void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
    inline void update(int x, T v) { for ( ; x <= n; x += x&-x) tr[x] = max(tr[x], v); }
    inline T query(int x) { T res = 0; for ( ; x; x -= x&-x) res = max(res, tr[x]); return res; }
} BIT;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        dp[i] = BIT.query(a[i])+1;
        BIT.update(a[i], dp[i]);
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}
