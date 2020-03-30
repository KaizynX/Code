/*
 * @Author: Kaizyn
 * @Date: 2020-03-25 16:37:56
 * @LastEditTime: 2020-03-25 20:52:49
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 5e5+7;
const int MOD = 998244353;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

template <typename T, typename U = greater<T>>
struct SegmentTree
{
    SegmentTree(){}
    void build(const int &_n, const T &k = 0) { n = _n; _build(1, n, k); }
    template <typename TT>
    void buiil(const int _n, const TT a[]) { n = _n; _build(1, n, a); }
    void modify(const int &x, const T &k) { _modify(x, k); }
    void modify(const int &l, const int &r, const T &k) { _modify(l, r, k); }
    void add(const int &x, const T &k) { _add(x, k); }
    T query(const int &x) { return _query(x, x); }
    T query(const int &l, const int &r) { return _query(l, r); }
private:
    struct TreeNode
    {
        int l, r;
        T v, lazy;
    } tr[N<<2];
    int n;
    T init_val = cmp(0, 1) ? INF : -INF;
    U cmp = U();
    T mv(const T &x, const T &y) { return cmp(x, y) ? x : y;}
    void update(const int &i, const T &k) { tr[i].v = mv(tr[i].v, k); tr[i].lazy = mv(tr[i].lazy, k); }
    void push_up(const int &i) { tr[i].v = mv(tr[i<<1].v, tr[i<<1|1].v); }
    void push_down(const int &i) {
        if (tr[i].lazy == init_val) return;
        update(i<<1, tr[i].lazy);
        update(i<<1|1, tr[i].lazy);
        tr[i].lazy = init_val;
    }
    void _build(const int &l, const int &r, const T &k = 0, const int &i = 1) {
        tr[i].lazy = init_val;
        tr[i].l = l; tr[i].r = r;
        if (l == r) { tr[i].v = k; return; }
        int mid = (l+r)>>1;
        _build(l, mid, k, i<<1);
        _build(mid+1, r, k, i<<1|1);
        push_up(i);
    }
    template <typename TT>
    void _build(const int &l, const int &r, const TT a[], const int &i = 1) {
        tr[i].lazy = init_val;
        tr[i].l = l; tr[i].r = r;
        if (l == r) { tr[i].v = a[l]; return; }
        int mid = (l+r)>>1;
        _build(l, mid, a, i<<1);
        _build(mid+1, r, a, i<<1|1);
        push_up(i);
    }
    void _modify(const int &l, const int &r, const T &k, const int &i = 1) {
        if (tr[i].l  >= l && tr[i].r <= r) { update(i, k); return; }
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (l <= mid) _modify(l, r, k, i<<1);
        if (r >  mid) _modify(l, r, k, i<<1|1);
        push_up(i);
    }
    void _add(const int &x, const T &k, const int &i = 1) {
        if (tr[i].l == x && tr[i].r == x) { tr[i].v += k; return; }
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (x <= mid) _add(x, k, i<<1);
        else _add(x, k, i<<1|1);
        push_up(i);
    }
    T _query(const int &l, const int &r, const int &i = 1) {
        if (tr[i].l  >= l && tr[i].r <= r) return tr[i].v;
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        T res = init_val;
        if (l <= mid) res = mv(res, _query(l, r, i<<1));
        if (r >  mid) res = mv(res, _query(l, r, i<<1|1));
        return res;
    }
};

template <int _MOD> struct Mint
{
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
using mint = Mint<MOD>;


struct Node
{
    int l, r, x;
    friend istream& operator >> (istream &is, Node &nd) {
        return is >> nd.l >> nd.r >> nd.x;
    }
};

int n, k, m;
int add[N];
mint dp[N], sum[N];
Node a[N];
SegmentTree<int> ST;

inline void solve()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= m; ++i) cin >> a[i];

    mint res = 1;
    for (int b = 0; b < k; ++b) {
        memset(add, 0, sizeof(int)*(n+3));
        ST.build(n+1);
        for (int i = 1; i <= m; ++i) {
            if ((a[i].x>>b)&1) ++add[a[i].l], --add[a[i].r+1];
            else ST.modify(a[i].r+1, n+1, a[i].l);
        }
        #ifdef DEBUG
        for (int i = 1; i <= n+1; ++i) cout << ST.query(i) << " \n"[i==n+1];
        #endif
        sum[0] = dp[0] = 1;
        for (int i = 1, cur = 0; i <= n+1; ++i) {
            cur += add[i];
            if (cur > 0) dp[i] = 0;
            else {
                dp[i] = sum[i-1];
                int last = ST.query(i);
                if (last) dp[i] -= sum[last-1];
            }
            sum[i] = sum[i-1]+dp[i];
        }
        res *= dp[n+1];
    }
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}