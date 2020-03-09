#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;
const int M = 4e6+7;

template <typename T>
struct PersistenceSegmentTree
{
    static const int NN = N*(log2(N)+3);
    int rt[N], sum[NN], ls[NN], rs[NN], tot, sz;
    vector<T> des;
    void build(T a[], const int &n) {
        vector<T>(a+1, a+n+1).swap(des);
        sort(des.begin(), des.end());
        des.erase(unique(des.begin(), des.end()), des.end());
        sz = des.size();
        tot = 0;
        rt[0] = _build(1, sz);
        for (int i = 1; i <= n; ++i) {
            int t = lower_bound(des.begin(), des.end(), a[i])-des.begin()+1;
            rt[i] = _update(rt[i-1], 1, sz, t);
        }
    }
    void update(const int &id, const T &k) {
        int t = lower_bound(des.begin(), des.end(), k)-des.begin()+1;
        rt[id] = _update(rt[id-1], 1, sz, t);
    }
    T query(const int &l, const int &r, const int &k) {
        return des[_query(rt[l-1], rt[r], 1, sz, k)-1];
    }
private:
    int _build(const int &l, const int &r) {
        int cur = ++tot;
        sum[++cur] = 0;
        if (l >= r) return cur;
        int mid = (l+r)>>1;
        ls[cur] = _build(l, mid);
        rs[cur] = _build(mid+1, r);
        return cur;
    }
    int _update(const int &pre, const int &l, const int &r, const int &k) {
        int cur = ++tot;
        ls[cur] = ls[pre]; rs[cur] = rs[pre]; sum[cur] = sum[pre]+1;
        if (l >= r) return cur;
        int mid = (l+r)>>1;
        if (k <= mid) ls[cur] = _update(ls[pre], l, mid, k);
        else rs[cur] = _update(rs[pre], mid+1, r, k);
        return cur;
    }
    int _query(const int &u, const int &v, const int &l, const int &r, const int &k) {
        if (l >= r) return l;
        int num = sum[ls[v]]-sum[ls[u]], mid = (l+r)>>1;
        if (num >= k) return _query(ls[u], ls[v], l, mid, k);
        else return _query(rs[u], rs[v], mid+1, r, k-num);
    }
};

int n, m;
int a[N];
PersistenceSegmentTree<int> PST;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a+i);
    PST.build(a, n);
    for (int i = 1, l, r, k; i <= m; ++i) {
        scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", PST.query(l, r, k));
    }
    return 0;
}
