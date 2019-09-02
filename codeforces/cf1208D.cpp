#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+7;

int n;
int p[MAXN];
long long s[MAXN], a[MAXN];

struct BinaryIndexedTree
{
    // set your type
    typedef long long T;
    T tr[MAXN];
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
        cin >> s[i];
        a[i] = a[i-1]+i;
    }
    for (int i = n; i; --i) {
        int l = 0, r = n-1;
        while (l < r) {
            int mid = (l+r+1)>>1;
            if (a[mid]+BIT.query(mid) <= s[i]) l = mid;
            else r = mid-1;
        }
        p[i] = l+1;
        BIT.update(l+1, n, -l-1);
    }
    for (int i = 1; i <= n; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;
    return 0;
}
