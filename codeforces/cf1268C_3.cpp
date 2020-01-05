#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;

int n;
int a[N], p[N];
long long res[N];

struct BinaryIndexedTree
{
    typedef long long T;
    T tr[N];
    BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
    inline void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
    inline void update(int x, T v) { for ( ; x <= n; x += x&-x) tr[x] += v; }
    inline void update(int x, int y, T v) { update(x, v); update(y+1, -v); }
    inline T query(int x) { T res = 0; for ( ; x; x -= x&-x) res += tr[x]; return res; }
    inline T query(int x, int y) { return query(y)-query(x-1); }
} pos, mv, st;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
        pos.update(i, i);
        mv.update(i, 1);
    }

    long long sum = 0;
    for (int i = 1, l = p[1], r = p[1]; i <= n; ++i) {
        pos.update(p[i], -p[i]); mv.update(p[i], -1);
        l = min(l, p[i]);
        r = max(r, p[i]);
        sum += st.query(p[i], n);
        st.update(p[i], 1);
#ifdef DEBUG
        cout << pos.query(l, (l+r)/2) << " " << mv.query(l, (l+r)/2) << "|"
             << pos.query((l+r)/2, r) << " " << mv.query((l+r)/2+1, r) << endl; 
#endif
        res[i] = sum+
            pos.query(l, (l+r)/2)-mv.query(l, (l+r)/2)*l+
            mv.query((l+r)/2+1, r)*r-pos.query((l+r)/2+1, r);
        cout << res[i] << " \n"[i==n];
    }
    return 0;
}

