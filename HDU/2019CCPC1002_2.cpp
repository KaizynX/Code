#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5+7;
const int kM = 2e6+7;

int T, n, m, tr_id;
int root[kN], a[kN], f[kN];

struct Tree
{
    int sum = 0, ls = 0, rs = 0, f = 0;
} tr[kM];

void build_tree(int li, int ri, int l, int r, int v)
{
    tr[ri] = tr[li];
    ++tr[ri].sum;
    if (l == r) return;
    int mid = (l+r)>>1;
    if (v <= mid) build_tree(tr[li].ls, (tr[ri].ls = ++tr_id), l, mid, v);
    else build_tree(tr[li].rs, (tr[ri].rs = ++tr_id), mid+1, r, v);
}

void del_tree(int i, int l, int r, int v, int f)
{
    if (tr[i].f == f) return;
    tr[i].f = f;
    --tr[i].sum;
    if (l == r) return;
    int mid = (l+r)>>1;
    if (v <= mid) del_tree(tr[i].ls, l, mid, v, f);
    else del_tree(tr[i].rs, mid+1, r, v, f);
}

int query_tree(int i, int l, int r, int k)
{
    if (!i) return max(l, k);
    // 如果当前区间的值都有a[i]对应，则查询失败
    if (tr[i].sum == r-l+1) return 0;
    // 查询到一个值l，到这一步了保证 l >= k
    if (l == r) return l;
    int mid = (l+r)>>1;
    // k在右边区间，直接舍弃左边区间
    if (k > mid) return query_tree(tr[i].rs, mid+1, r, k);
    // 此时k一定在左区间
    int res = query_tree(tr[i].ls, l, mid, k);
    // 左区间没找到找右边
    return res ? res : query_tree(tr[i].rs, mid+1, r, k);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        // init
        tr_id = 0;
        int last_ans = 0;
        for (int i = 1; i <= n; ++i) {
            root[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
            build_tree(root[i-1], (root[i] = ++tr_id), 1, n, a[i]);
        }
        for (int i = 1, op, t1, t2, pos, r, k; i <= m; ++i) {
            scanf("%d%d", &op, &t1);
            if (op == 1) {
                pos = t1^last_ans;
                if (!a[pos]) continue;
                for (int i = pos; i <= n; ++i) {
                    del_tree(root[i], 1, n, a[pos], i);
                }
                a[pos] = 0;
            } else {
                scanf("%d", &t2);
                r = t1^last_ans;
                k = t2^last_ans;
                last_ans = query_tree(root[r], 1, n, k);
                if (!last_ans) last_ans = n+1;
                printf("%d\n", last_ans);
            }
        }
    }
    return 0;
}
