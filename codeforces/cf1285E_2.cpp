#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int INF = 2e9;

int n, m, T;
vector<int> t, f;

struct Node
{
    int l, r;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.l < n2.l;
    }
} a[N];

struct SegmenTree
{
    struct TreeNode
    {
        int l, r, add;
        int cnt[2];
    } tr[N<<2];
    void push_up(int i) {
        tr[i].cnt[0] = tr[i<<1].cnt[0]+tr[i<<1|1].cnt[0];
        tr[i].cnt[1] = tr[i<<1].cnt[1]+tr[i<<1|1].cnt[1];
    }
    void push_down(int i) {
        if (!tr[i].add) return;
        tr[i<<1].add += tr[i].add;
        tr[i<<1|1].add += tr[i].add;
        if (tr[i].add == 1) {
            tr[i<<1].cnt[1] = tr[i<<1].cnt[0];
            tr[i<<1|1].cnt[1] = tr[i<<1|1].cnt[0];
            tr[i<<1].cnt[0] = 0;
            tr[i<<1|1].cnt[0] = 0;
        } else {
            tr[i<<1].cnt[0] = 0;
            tr[i<<1|1].cnt[0] = 0;
            tr[i<<1].cnt[1] = 0;
            tr[i<<1|1].cnt[1] = 0;
        }
        tr[i].add = 0;
    }
    void build(int i, int l, int r) {
        tr[i].l = l; tr[i].r = r;
        tr[i].add = 0;
        if (l == r) {
            tr[i].add = 0;
            tr[i].cnt[0] = 1;
            tr[i].cnt[1] = 0;
            return;
        }
        int mid = (l+r)>>1;
        build(i<<1, l, mid);
        build(i<<1|1, mid+1, r);
        push_up(i);
    }
    void update(int i, int l, int r) {
        if (tr[i].l >= l && tr[i].r <= r) {
            ++tr[i].add;
            tr[i].cnt[1] = tr[i].cnt[0];
            tr[i].cnt[0] = 0;
            return;
        }
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (l <= mid) update(i<<1, l, r);
        if (r >  mid) update(i<<1|1, l, r);
        push_up(i);
    }
    int query(int i, int l, int r) {
        if (tr[i].l >= l && tr[i].r <= r) return tr[i].cnt[1];
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1, res = 0;
        if (l <= mid) res += query(i<<1, l, r);
        if (r >  mid) res += query(i<<1|1, l, r);
        return res;
    }
} ST;

void descrete()
{
    static vector<int> d;
    d.resize(n*2, 0);
    for (int i = 1; i <= n; ++i) {
        d[i*2-2] = a[i].l;
        d[i*2-1] = a[i].r;
    }
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    m = d.size()*2-1;
    for (int i = 1; i <= n; ++i) {
        a[i].l = lower_bound(d.begin(), d.end(), a[i].l)-d.begin()+1;
        a[i].r = lower_bound(d.begin(), d.end(), a[i].r)-d.begin()+1;
        a[i].l = a[i].l*2-1;
        a[i].r = a[i].r*2-1;
    }
}

#ifdef DEBUG
inline void print_tree()
{
    puts("*************");
    for (int i = 1; i <= n<<2; ++i)
        printf("%d (%d %d %d %d)\n", i, ST.tr[i].l, ST.tr[i].r, ST.tr[i].cnt[0], ST.tr[i].cnt[1]);
    puts("*************");
}

inline void print_line()
{
    puts("~~~~~~~~~~~~~~");
    for (int i = 1; i <= n; ++i)
        printf("(%d %d)\n", a[i].l, a[i].r);
    puts("~~~~~~~~~~~~~~");
}
#endif

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &a[i].l, &a[i].r);
        }
        sort(a+1, a+n+1);
        descrete();
        t.resize(m+1, 0);
        f.resize(m+1, 0);
        for (int i = 1, last = 0; i <= n; ++i) {
            if (a[i].l > last) {
                f[last] = 1;
                f[a[i].l] = 1;
            }
            ++t[a[i].l];
            ++t[a[i].r];
            last = max(last, a[i].r);
        }
        f[a[n].r] = 1;
        ST.build(1, 1, m);
#ifdef DEBUG
        print_line();
#endif
        for (int i = 1; i <= n; ++i) {
            ST.update(1, a[i].l, a[i].r);
        }
#ifdef DEBUG
            print_tree();
#endif
        int base = ST.tr[1].cnt[0]+1, res = 0;
        for (int i = 1; i <= n; ++i) {
            int now = base+ST.query(1, a[i].l, a[i].r);
            if ((f[a[i].l] && t[a[i].l] == 1) || (f[a[i].r] && t[a[i].r] == 1))
                now -= 2;
            res = max(res, now);
        }
        printf("%d\n", res);
    }
    return 0;
}
