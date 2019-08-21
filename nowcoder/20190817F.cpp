#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int kN = 1e5+7;

int n, r, num_x, num_y, ans;
int pos_x[kN], sum_x[kN], sum_y[kN];
// sum_x[i] sum(x = i, i+r, i+2r)
// pos_x[i] first a[ ].x == i
//          a[pos_x[i]].x == i
//          if there is no x == i, then pos_x[i]->nex x

struct Point
{
    int x, y;
    bool operator < (const Point &nex) const { return x < nex.x; }
} a[kN];

struct Tree
{
    int l, r, mv = 0;
} tr[kN<<2];

inline void push_up(int i)
{
    tr[i].mv = max(tr[i<<1].mv, tr[i<<1|1].mv);
}

void build_tree(int i, int l, int r)
{
    tr[i].l = l; tr[i].r = r;
    if (l == r) {
        tr[i].mv = sum_y[l];
        return;
    }
    int mid = (l+r)/2;
    build_tree(i<<1, l, mid);
    build_tree(i<<1|1, mid+1, r);
    push_up(i);
}

void update_tree(int i, int k, int v)
{
    if (tr[i].l == k && tr[i].r == k) {
        tr[i].mv += v;
        return;
    }
    int mid = (tr[i].l+tr[i].r)/2;
    if (k <= mid) update_tree(i<<1, k, v);
    else update_tree(i<<1|1, k, v);
    push_up(i);
}

int main()
{
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &a[i].x, &a[i].y);
        ++a[i].x; ++a[i].y;
        ++sum_x[a[i].x];
        if (a[i].x-r > 0) ++sum_x[a[i].x-r];
        if (a[i].x-r-r > 0) ++sum_x[a[i].x-r-r];
        ++sum_y[a[i].y];
        if (a[i].y-r > 0) ++sum_y[a[i].y-r];
        if (a[i].y-r-r > 0) ++sum_y[a[i].y-r-r];
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) {
        if (!pos_x[a[i].x]) pos_x[a[i].x] = i;
    }
    pos_x[100002] = n+1;
    for (int i = 100001; i; --i)
        if (!pos_x[i]) pos_x[i] = pos_x[i+1];

    build_tree(1, 1, 100001);
    for (int i = 1; i <= n; i = pos_x[a[i].x+1]) {
        for (int nowx = a[i].x; nowx <= min(a[i].x+r+r, 100001); nowx += r) {
            for (int j = pos_x[nowx]; j < pos_x[nowx+1]; ++j) {
                update_tree(1, a[j].y, -1);
                if (a[j].y-r > 0) update_tree(1, a[j].y-r, -1);
                if (a[j].y-r-r > 0) update_tree(1, a[j].y-r-r, -1);
            }
        }
        ans = max(ans, sum_x[a[i].x]+tr[1].mv);
#ifdef DEBUG
        printf("%d %d %d\n", a[i].x, sum_x[a[i].x], tr[1].mv);
#endif
        for (int nowx = a[i].x; nowx <= min(a[i].x+r+r, 100001); nowx += r) {
            for (int j = pos_x[nowx]; j < pos_x[nowx+1]; ++j) {
                update_tree(1, a[j].y, 1);
                if (a[j].y-r > 0) update_tree(1, a[j].y-r, 1);
                if (a[j].y-r-r > 0) update_tree(1, a[j].y-r-r, 1);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
