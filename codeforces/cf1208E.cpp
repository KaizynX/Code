#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6+7;
const int INF = 1e9;

int n, w, l;
int a[MAXN];
long long col[MAXN];

struct Tree
{
    int l, r, mv = -INF;
} tr[MAXN<<2];

inline int ls(int x) { return x<<1; }
inline int rs(int x) { return x<<1|1; }

inline void push_up(int i)
{
    tr[i].mv = max(tr[ls(i)].mv, tr[rs(i)].mv);
}

void build_tree(int i, int l, int r)
{
    tr[i].l = l; tr[i].r = r;
    if(l == r) { tr[i].mv = a[l]; return; }
    int mid = (l+r)>>1;
    build_tree(ls(i), l, mid);
    build_tree(rs(i), mid+1, r);
    push_up(i);
}

int query_tree(int i, int l, int r)
{
    if(tr[i].l >= l && tr[i].r <= r) return tr[i].mv;
    int mid = (tr[i].l+tr[i].r)>>1;
    int res = -INF;
    if(l <= mid) res = max(res, query_tree(ls(i), l, r));
    if(r > mid)  res = max(res, query_tree(rs(i), l, r));
    return res;
}

int main()
{
    cin >> n >> w;
    for (int i = 1; i <= n; ++i) {
        cin >> l;
        for (int j = 1; j <= l; ++j) {
            cin >> a[j];
        }
        build_tree(1, 1, l);
        for (int j = 1; j <= w; ++j) {
            int tmp = query_tree(1, max(1, j-(w-l)), min(l, j));
            if (j-(w-l) < 1 || j > l) tmp = max(tmp, 0);
            col[j] += tmp;
        }
    }
    for (int i = 1; i <= w; ++i) {
        cout << col[i] << " ";
    }
    cout << endl;
    return 0;
}
