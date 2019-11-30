#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 1e6+7;

int n;
char a[N];
string s;
set<int> p;

struct SegmentTree
{
    struct Node
    {
        int l, r, minv = 0, maxv = 0, add = 0, tag = 0;
    } tr[N<<2];
    void push_up(int i) {
        tr[i].tag = tr[i<<1].tag|tr[i<<1|1].tag;
        if (tr[i<<1].tag && tr[i<<1|1].tag) {
            tr[i].minv = min(tr[i<<1].minv, tr[i<<1|1].minv);
            tr[i].maxv = max(tr[i<<1].maxv, tr[i<<1|1].maxv);
        } else if (tr[i<<1].tag) {
            tr[i].minv = tr[i<<1].minv;
            tr[i].maxv = tr[i<<1].maxv;
        } else if (tr[i<<1|1].tag) {
            tr[i].minv = tr[i<<1|1].minv;
            tr[i].maxv = tr[i<<1|1].maxv;
        } else {
            tr[i].minv = tr[i].maxv = 0;
        }
    }
    void push_down(int i) {
        if (!tr[i].add) return;
        if (tr[i<<1].tag) {
            tr[i<<1].minv += tr[i].add;
            tr[i<<1].maxv += tr[i].add;
            tr[i<<1].add += tr[i].add;
        }
        if (tr[i<<1|1].tag) {
            tr[i<<1|1].minv += tr[i].add;
            tr[i<<1|1].maxv += tr[i].add;
            tr[i<<1|1].add += tr[i].add;
        }
        tr[i].add = 0;
    }
    void build(int i, int l, int r) {
        tr[i].l = l; tr[i].r = r;
        if (l == r) return;
        int mid = (l+r)>>1;
        build(i<<1, l, mid);
        build(i<<1|1, mid+1, r);
    }
    void update1(int i, int x, int k, int flag) {
        if (tr[i].l == x && tr[i].r == x) {
            tr[i].minv = tr[i].maxv = k;
            tr[i].tag = flag;
            return;
        }
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (x <= mid) update1(i<<1, x, k, flag);
        else update1(i<<1|1, x, k, flag);
        push_up(i);
    }
    void update2(int i, int l, int r, int k) {
        if (tr[i].l >= l && tr[i].r <= r) {
            if (tr[i].tag) {
                tr[i].add += k;
                tr[i].minv += k;
                tr[i].maxv += k;
            }
            return;
        }
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (l <= mid && tr[i<<1].tag) update2(i<<1, l, r, k);
        if (r > mid && tr[i<<1|1].tag) update2(i<<1|1, l, r, k);
        push_up(i);
    }
    int query(int i, int x) {
        if (tr[i].l == x && tr[i].r == x) return tr[i].minv;
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (x <= mid) return query(i<<1, x);
        else return query(i<<1|1, x);
    }
} ST;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    ST.build(1, 1, n);
    int cur = 1;
    for (char c : s) {
        if (c == '(') {
            if (a[cur] == '(') ;
            else if (a[cur] == ')') {
                ST.update2(1, cur, n, 2);
            } else {
                p.insert(cur);
                int last;
                auto it = p.lower_bound(cur);
                if (it == p.begin()) last = 0;
                else last = ST.query(1, *(--it));
                ST.update1(1, cur, last+1, 1);
                ST.update2(1, cur+1, n, 1);
            }
            a[cur] = '(';
        } else if (c == ')') {
            if (a[cur] == ')') ;
            else if (a[cur] == '(') {
                ST.update2(1, cur, n, -2);
            } else {
                p.insert(cur);
                int last;
                auto it = p.lower_bound(cur);
                if (it == p.begin()) last = 0;
                else last = ST.query(1, *(--it));
                ST.update1(1, cur, last-1, 1);
                ST.update2(1, cur+1, n, -1);
            }
            a[cur] = ')';
        } else if (c == 'R') {
            ++cur;
        } else if (c == 'L') {
            if (cur > 1) --cur;
        } else {
            if (a[cur] == '(') {
                p.erase(cur);
                ST.update1(1, cur, 0, 0);
                ST.update2(1, cur+1, n, -1);
            } else if (a[cur] == ')') {
                p.erase(cur);
                ST.update1(1, cur, 0, 0);
                ST.update2(1, cur+1, n, 1);
            }
            a[cur] = c;
        }
        if ((p.size() && ST.query(1, *p.rbegin())) || ST.tr[1].minv < 0) cout << -1 << " ";
        else cout << ST.tr[1].maxv << " ";
#ifdef DEBUG
        cout << "   ";
        for (int i = 1; i <= 20; ++i) cout << a[i];
        cout << endl;
#endif
    }
    cout << endl;
    return 0;
}
