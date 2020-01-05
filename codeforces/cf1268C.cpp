#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;

int n;
int a[N], p[N], mv[N], st[N];
long long res[N];

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
        p[a[i]] = i;
    }

    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        st[i] = BIT.query(p[i], n);
        mv[i] = min(st[i], BIT.query(1, p[i]));
#ifdef DEBUG
        cout << "(" << BIT.query(1, p[i]) << ", " << st[i] << ") ";
#endif
        BIT.update(p[i], 1);
        sum += st[i];
        res[i] = sum;
    }
    sum = 0;
    for (int i = n-1; i; --i) {
        sum += mv[i+1];
        res[i] += sum;
    }
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
