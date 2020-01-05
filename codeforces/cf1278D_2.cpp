#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+7;
const int M = 1e6+7;
const int NN = 1e7+7;

int n, m, top;
int sta[N];

struct Node
{
    int l, r;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.l < n2.l;
    }
    friend istream &operator >> (istream &is, Node &node) {
        return is >> node.l >> node.r;
    }
} a[N];

struct Tree
{
    struct TreeNode
    {
        int sum = 0, ls, rs;
    } tr[NN];

    int tr_id = 0;
    int root[N];

    void build(int li, int ri, int l, int r, int v)
    {
        tr[ri] = tr[li];
        ++tr[ri].sum;
        if (l == r) return;
        int mid = (l+r)>>1;
        if (v <= mid) build(tr[li].ls, (tr[ri].ls = ++tr_id), l, mid, v);
        else build(tr[li].rs, (tr[ri].rs = ++tr_id), mid+1, r, v);
    }
    int query(int i, int l, int r, int x) {
        if (!x) return 0;
        if (r <= x) return tr[i].sum;
        int mid = (l+r)>>1, res = query(tr[i].ls, l, mid, x);
        if (x > mid) res += query(tr[i].rs, mid+1, r, x);
        return res;
    }
} TT;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    m = n*2;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) {
        TT.build(TT.root[i-1], (TT.root[i] = ++TT.tr_id), 1, m, a[i].r);
    }
    long long edge = 0;
    for (int i = 1; i <= n; ++i) {
        edge += TT.query(TT.root[i-1], 1, m, a[i].r)-TT.query(TT.root[i], 1, m, a[i].l-1);
    }
    if (edge != n-1) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (top && a[i].r <= a[sta[top]].r) continue;
        sta[++top] = i;
    }
    for (int i = 3; i <= top; ++i) {
        if (a[sta[i]].l < a[sta[i-2]].r) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
