#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, m, r, p;

struct Mint
{
    int  _MOD = p;
    int v = 0;
    Mint() {}
    Mint(int _v) : v((_v%_MOD+_MOD)%_MOD) {}
    Mint(long long _v) : v(static_cast<int>((_v%_MOD+_MOD)%_MOD)) {}
    Mint operator = (const int &_v) { return *this = Mint(_v); }
    Mint operator = (const long long &_v) { return *this = Mint(_v); }
    bool operator ! () const { return !this->v; }
    bool operator < (const Mint &b) const { return v < b.v; }
    bool operator > (const Mint &b) const { return v > b.v; }
    bool operator == (const Mint &b) const { return v == b.v; }
    bool operator != (const Mint &b) const { return v != b.v; }
    bool operator <= (const Mint &b) const { return v < b.v || v == b.v; }
    bool operator >= (const Mint &b) const { return v > b.v || v == b.v; }
    Mint operator + (const Mint &b) const { return Mint(v+b.v); }
    Mint operator - (const Mint &b) const { return Mint(v-b.v); }
    Mint operator * (const Mint &b) const { return Mint(1ll*v*b.v); }
    Mint operator / (const Mint &b) const { return Mint(b.inv()*v); }
    Mint& operator += (const Mint &b) { return *this = *this+b; }
    Mint& operator -= (const Mint &b) { return *this = *this-b; }
    Mint& operator *= (const Mint &b) { return *this = *this*b; }
    Mint& operator /= (const Mint &b) { return *this = *this/b; }
    Mint operator - () const { return Mint(-v); }
    Mint& operator ++ () { return *this += 1; }
    Mint& operator -- () { return *this -= 1; }
    Mint operator ++ (int) { Mint tmp = *this; *this += 1; return tmp; }
    Mint operator -- (int) { Mint tmp = *this; *this -= 1; return tmp; }
    Mint pow(int p) const {
        Mint res(1), x(*this);
        while (p) {
            if (p&1) res = res*x;
            x *= x;
            p >>= 1;
        }
        return res;
    }
    Mint inv() const { return pow(_MOD-2); }
    friend istream& operator >> (istream &is, Mint &mt) { return is >> mt.v; }
    friend ostream& operator << (ostream &os, const Mint &mt) { return os << mt.v; }
};

template <typename T>
struct SegmentTree
{
    int sz;
    T tr[N<<2], lazy[N<<2];
    SegmentTree(){}
    void build(const int &n) { sz = n; _build(1, n); }
    template <typename TT>
    void build(const TT a[], const int &n) { sz = n; _build(a, 1, n); }
    void modify(const int &x, const T &k) { _modify(x, k, 1, sz); }
    void add(const int &x, const T &k) { _add(x, x, k, 1, sz); }
    void add(const int &l, const int &r, const T &k) { _add(l, r, k, 1, sz); }
    T query(const int &x) { return _query(x, x, 1, sz); }
    T query(const int &l, const int &r) { return _query(l, r, 1, sz); }
private :
    void push_up(const int &i) { tr[i] = tr[i<<1]+tr[i<<1|1]; }
    void push_down(const int &i, const int &len) {
        if (!lazy[i]) return;
        tr[i<<1] += lazy[i]*(len-len/2);
        tr[i<<1|1] += lazy[i]*(len/2);
        lazy[i<<1] += lazy[i];
        lazy[i<<1|1] += lazy[i];
        lazy[i] = 0;
    }
    void _build(const int &l, const int &r, const int &i = 1) {
        lazy[i] = 0;
        if (l == r) { tr[i] = 0; return; }
        int mid = (l+r)>>1;
        _build(l, mid, i<<1);
        _build(mid+1, r, i<<1|1);
        push_up(i);
    }
    template <typename TT>
    void _build(const TT a[], const int &l, const int &r, const int &i = 1) {
        lazy[i] = 0;
        if (l == r) { tr[i] = a[l]; return; }
        int mid = (l+r)>>1;
        _build(a, l, mid, i<<1);
        _build(a, mid+1, r, i<<1|1);
        push_up(i);
    }
    void _modify(const int &x, const T &k, const int &trl, const int &trr, const int &i = 1) {
        if (trl == x && trr == x) {
            tr[i] = k;
            lazy[i] = 0;
            return;
        }
        push_down(i, trr-trl+1);
        int mid = (trl+trr)>>1;
        if (x <= mid) _modify(x, k, trl, mid, i<<1);
        else _modify(x, k, mid+1, trr, i<<1|1);
        push_up(i);
    }
    void _add(const int &l, const int &r, const T &k, const int &trl, const int &trr, const int &i = 1) {
        if (trl >= l && trr <= r) {
            tr[i] += k*(trr-trl+1);
            lazy[i] += k;
            return;
        }
        push_down(i, trr-trl+1);
        int mid = (trl+trr)>>1;
        if (l <= mid) _add(l, r, k, trl, mid, i<<1);
        if (r >  mid) _add(l, r, k, mid+1, trr, i<<1|1);
        push_up(i);
    }
    T _query(const int &l, const int &r, const int &trl, const int &trr, const int &i = 1) {
        if (trl >= l && trr <= r) return tr[i];
        push_down(i, trr-trl+1);
        int mid = (trl+trr)>>1;
        T res = 0;
        if (l <= mid) res += _query(l, r, trl, mid, i<<1);
        if (r >  mid) res += _query(l, r, mid+1, trr, i<<1|1);
        return res;
    }
};

template <typename T>
struct ShuPou
{
    int dfn;
    int f[N], d[N], num[N], son[N], rk[N], id[N], tp[N];
    T init_val[N];
    SegmentTree<T> ST;
    template <typename TT, typename EDGE>
    void build(const EDGE e[], const TT a[], const int &n, const int &rt = 1) {
        memset(son, 0, sizeof son);
        d[0] = num[0] = dfn = 0;
        dfs1(e, rt);
        dfs2(e, rt, rt);
        for (int i = 1; i <= n; ++i)
            init_val[i] = a[rk[i]];
        ST.build(init_val, n);
    }
    template <typename EDGE>
    void dfs1(const EDGE e[], const int &u = 1, const int &fa = 0) {
        f[u] = fa;
        d[u] = d[fa]+1;
        num[u] = 1;
        for (auto v : e[u]) if (v != fa) {
            dfs1(e, v, u);
            num[u] += num[v];
            if (num[v] > num[son[u]])
                son[u] = v;
        }
    }
    template <typename EDGE>
    void dfs2(const EDGE e[], const int &u = 1, const int &t = 1) {
        tp[u] = t;
        id[u] = ++dfn;
        rk[dfn] = u;
        if (!son[u]) return;
        dfs2(e, son[u], t);
        for (auto v : e[u]) if (v != son[u] && v != f[u])
            dfs2(e, v, v);
    }
    void add_sons(const int &x, const T &k) { ST.add(id[x], id[x]+num[x]-1, k); }
    void add(int x, int y, const T &k) {
        while (tp[x] != tp[y]) {
            if (d[tp[x]] < d[tp[y]]) swap(x, y);
            ST.add(id[tp[x]], id[x], k);
            x = f[tp[x]];
        }
        if (d[x] > d[y]) swap(x, y);
        ST.add(id[x], id[y], k);
    }
    T query_sons(const int &x) { return ST.query(id[x], id[x]+num[x]-1); }
    T query(int x, int y) {
        T res = 0;
        while (tp[x] != tp[y]) {
            if (d[tp[x]] < d[tp[y]]) swap(x, y);
            res += ST.query(id[tp[x]], id[x]);
            x = f[tp[x]];
        }
        if (d[x] > d[y]) swap(x, y);
        return res+ST.query(id[x], id[y]);
    }
};

int a[N];
list<int> e[N];
ShuPou<Mint> SP;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> r >> p;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    SP.build(e, a, n, r);
    for (int i = 1, op, x, y, z; i <= m; ++i) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> z;
            SP.add(x, y, z);
        } else if (op == 2) {
            cin >> x >> y;
            cout << SP.query(x, y) << endl;
        } else if (op == 3) {
            cin >> x >> z;
            SP.add_sons(x, z);
        } else if (op == 4) {
            cin >> x;
            cout << SP.query_sons(x) << endl;
        }
    }
    return 0;
}
