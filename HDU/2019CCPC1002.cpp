#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5+7;
const int kM = 2e6+7;

int T, n, m, tr_id;
int root[kN], a[kN], f[kN];

struct XianDuansShu
{
    int tt[kN<<2];

    void build(int i, int l, int r)
    {
        tt[i] = 0;
        if (l == r) return;
        int mid = (l+r)<<1;
        build(i<<1, l, mid);
        build(i<<1|1, mid+1, r);
    }
    void update(int i, int l, int r, int v)
    {
        ++tt[i];
        if (l == r) return;
        int mid = (l+r)>>1;
        if (v <= mid) update(i<<1, l, mid, v);
        else update(i<<1|1, mid+1, r, v);
    }
} XDS;

struct Tree
{
    int sum = 0, ls = 0, rs = 0;
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

int query_tree(int ti, int i, int l, int r, int k)
{
    if (!i) return max(l, k);
    // �����ǰ�����ֵ����a[i]��Ӧ�����ѯʧ��
    if (tr[i].sum-XDS.tt[ti] == r-l+1) return 0;
    // ��ѯ��һ��ֵl������һ���˱�֤ l >= k
    if (l == r) return l;
    int mid = (l+r)>>1;
    // k���ұ����䣬ֱ�������������
    if (k > mid) return query_tree(ti<<1|1, tr[i].rs, mid+1, r, k);
    // ��ʱkһ����������
    int res = query_tree(ti<<1, tr[i].ls, l, mid, k);
    // ������û�ҵ����ұ�
    return res ? res : query_tree(ti<<1|1, tr[i].rs, mid+1, r, k);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        // init
        tr_id = 0;
        int last_ans = 0;
        XDS.build(1, 1, n);
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
                XDS.update(1, 1, n, a[pos]);
            } else {
                scanf("%d", &t2);
                r = t1^last_ans;
                k = t2^last_ans;
                last_ans = query_tree(1, root[r], 1, n, k);
                if (!last_ans) last_ans = n+1;
                printf("%d\n", last_ans);
            }
        }
    }
    return 0;
}
