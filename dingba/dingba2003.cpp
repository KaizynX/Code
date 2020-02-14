#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n;
int a[N];
long long d, res;
long long s[N];
pair<long long, int> b[N];
pair<int, int> q[N];

struct BinaryIndexedTree
{
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
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i-1]+a[i];
        b[i] = {s[i], i};
    }
    sort(b, b+n+1);
    for (int i = 0; i <= n; ++i) s[i] = b[i].first;
    for (int i = 0; i <= n; ++i) {
        int p = upper_bound(s, s+n+1, b[i].first-d)-s;
        // s[i] - s[p~n] < d
        q[i] = {p, b[i].second};
    }
    sort(q, q+n+1);
    // 离线 对于 q[j] {p, i} 计算 p~n中有几个id >= i
    int j = n;
    while (j >= 0 && q[j].first > n) --j;
    for (int i = n; i >= 0; --i) {
        if (b[i].second) BIT.update(b[i].second, 1);
        while (j >= 0 && q[j].first == i) {
            if (!q[j].second) { --j; continue; }
            res += n-q[j].first+1-BIT.query(q[j].second, n);
            --j;
        }
    }
    cout << res << endl;
    return 0;
}
