#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e5+7;
const int K = 16;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

template <typename T>
struct TreeNode
{
    T num[18];
    void clear() { memset(num, 0, sizeof num); num[0] = 1; }
    friend TreeNode operator + (const TreeNode &t1, const TreeNode &t2) {
        TreeNode res;
        for (int i = 1; i <= K; ++i) res.num[i] = t1.num[i]+t2.num[i];
        return res;
    }
    TreeNode& operator += (const TreeNode &t) { return *this = *this+t; }
    long long sum(const int &x) {
        long long res = 0;
        for (int i = 1; i <= x && i <= K; ++i) res += num[i];
        return res;
    }
    #ifdef DEBUG
    void print() {
        for (int i = 1; i <= K; ++i) {
            cout << num[i] << " \n"[i==K];
        }
    }
    #endif
};

struct SegmentTree
{
    typedef TreeNode<long long> T;
    int sz;
    T tr[N<<2];
    SegmentTree(){}
    void build(const int &n) { sz = n; }
    void modify(const int &x, const T &k) { _modify(x, k, 1, sz); }
    T query() { return tr[1]; }
private :
    void push_up(const int &i) { tr[i] = tr[i<<1]+tr[i<<1|1]; }
    void _modify(const int &x, const T &k, const int &trl, const int &trr, const int &i = 1) {
        if (trl == x && trr == x) { tr[i] = k; return; }
        int mid = (trl+trr)>>1;
        if (x <= mid) _modify(x, k, trl, mid, i<<1);
        else _modify(x, k, mid+1, trr, i<<1|1);
        push_up(i);
    }
} BigST;

struct ST
{
    int sz, tot;
    int del[N], id[N];
    TreeNode<long long> tr[N], sum[N];
    void build(const int &n) {
        sz = n;
        memset(del, 0, sizeof del);
        del[1] = 1;
        for (int i = n/2; i; --i) {
            push_up(i);
            #ifdef DEBUG
            cout << i << "*********\n";
            tr[i].print();
            sum[i].print();
            #endif
        }
        id[1] = ++tot;
        BigST.modify(tot, sum[1]);
    }
    void push_up(const int &i) {
        tr[i].clear();
        sum[i].clear();
        if (!del[i<<1]) {
            sum[i] += sum[i<<1];
            for (int i = 0; i <= K; ++i)
                tr[i].num[i+1] += tr[i<<1].num[i];
        }
        if (!del[i<<1|1]) {
            sum[i] += sum[i<<1|1];
            for (int i = 0; i <= K; ++i)
                tr[i].num[i+1] += tr[i<<1|1].num[i];
        }
        if (!del[i<<1] && !del[i<<1|1]) {
            for (int len = 0; len <= K; ++len) {
                for (int j = 0; j <= len; ++j) {
                    tr[i].num[len+2] += tr[i<<1].num[j]*tr[i<<1|1].num[len-j];
                }
            }
        }
        sum[i] += tr[i];
    }
    void erase(const int &x) {
        del[x] = 1;
        id[x] = ++tot;
        BigST.modify(tot, sum[x]);
        for (int i = x-1; ; i >>= 1) {
            push_up(i);
            if (del[i]) {
                BigST.modify(id[i], sum[i]);
                break;
            }
        }
    }
} ST;

int tr[N][18];

int n, m;

inline void solve()
{
    cin >> n >> m;
    BigST.build(n);
    ST.build(n);
    char op;
    int x;
    while (m--) {
        cin >> op >> x;
        if (op == '-') ST.erase(x);
        else cout << BigST.query().sum(x) << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}