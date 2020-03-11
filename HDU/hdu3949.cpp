/*
 * @Author: Kaizyn
 * @Date: 2020-03-11 16:17:22
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-11 17:11:42
 * @FilePath: \Code\HDU\hdu3949.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e4+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

template <typename T>
struct XXJ
{
    int sz = sizeof(T)*8, zero;
    T tot;
    vector<T> b, rb, p;
    XXJ(){ init(); }
    void init() {
        tot = zero = 0;;
        vector<T>(sz, 0).swap(b);
        vector<T>().swap(rb);
        vector<T>().swap(p);
    }
    template <typename TT>
    void build(TT a[], const int &n) {
        init();
        for (int i = 1; i <= n; ++i) insert(a[i]);
    }
    void merge(const XXJ xj) {
        for (int i : xj.b) if (i) insert(i);
    }
    void insert(T x) {
        for (int i = sz-1; i >= 0; --i) if ((x>>i)&1) {
            if (!b[i]) { b[i] = x; return; }
            x ^= b[i];
        }
        zero = 1;
    }
    bool find(T x) {
        for (int i = sz-1; i >= 0; --i) if ((x>>i)&1) {
            if (!b[i]) { return false; }
            x ^= b[i];
        }
        return true;
    }
    T max_xor() {
        T res = 0;
        for (int i = sz-1; i >= 0; --i)
            if (~(res>>i)&1) res ^= b[i];
            // res = max(res, res^b[i]);
        return res;
    }
    T min_xor() {
        if (zero) return 0;
        for (int i = 0; i < sz; ++i)
            if (b[i]) return b[i];
    }
    void rebuild() {
        rb = b;
        vector<T>().swap(p);
        for (int i = sz-1; i >= 0; --i)
            for (int j = i-1; j >= 0; --j)
                if ((rb[i]>>j)&1) rb[i] ^= rb[j];
        for (int i = 0; i < sz; ++i)
            if (rb[i]) p.emplace_back(rb[i]);
        tot = ((T)1<<p.size())+zero;
    }
    T kth_min(T k) {
        if (k >= tot || k < 1) return -1;
        if (zero && k == 1) return 0;
        if (zero) --k;
        T res = 0;
        for (int i = (int)p.size()-1; i >= 0; --i)
            if ((k>>i)&1) res ^= p[i];
        return res;
    }
    T kth_max(const T &k) {
        return kth_min(tot-k);
    }
};

XXJ<long long> xxj;

inline void solve()
{
    int n, q;
    long long x;
    xxj.init();
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        xxj.insert(x);
    }
    xxj.rebuild();
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> x;
        cout << xxj.kth_min(x) << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        cout << "Case #" << i << ":\n";
        solve();
    }
    return 0;
}