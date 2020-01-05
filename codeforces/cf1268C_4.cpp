#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;

int n;
int a[N], p[N];
long long res[N];

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
} mv, st;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
        mv.update(i, 1);
    }

    long long sum = 0;
    mv.update(p[1], -1);
    st.update(p[1], 1);
    for (int i = 2, l = p[1], r = p[1]; i <= n; ++i) {
        mv.update(p[i], -1);
        l = min(l, p[i]);
        r = max(r, p[i]);
        sum += st.query(p[i], n);
        st.update(p[i], 1);
        int ll = l, rr = r;
        while (ll < rr) {
            int mid = (ll+rr+1)>>1;
            if (st.query(mid) > i/2) rr = mid-1;
            else ll = mid;
        }
        res[i] = sum+1ll*mv.query(l, ll)*i/2+1ll*mv.query(ll+1, r)*(i-i/2-1);
#ifdef DEBUG
        printf("%d (%d %d) (%d %d)\n", i, ll, st.query(l, ll), mv.query(l, ll), mv.query(ll+1, r));
#endif
    }
    for (int i = 1; i <= n; ++i)
        cout << res[i] << " \n"[i==n];
    return 0;
}


