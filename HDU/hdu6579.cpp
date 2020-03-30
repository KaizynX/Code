/*
 * @Author: Kaizyn
 * @Date: 2020-03-27 15:03:21
 * @LastEditTime: 2020-03-27 16:02:43
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e6+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

template <class T>
struct PreSumLB
{
    int tot, sz = sizeof(T)*8;
    vector<T> b[N];
    vector<int> p[N];
    PreSumLB() { init(); }
    void init() {
        tot = 0;
        vector<T>(sz, 0).swap(b[0]);
        vector<int>(sz, 0).swap(p[0]);
    }
    void append(T val) {
        int pos = ++tot;
        vector<T> &bb = b[tot];
        vector<int> &pp = p[tot];
        pp = p[tot-1];
        bb = b[tot-1];
        for (int i = sz-1; i >= 0; --i) if ((val>>i)&1) {
            if (bb[i]) {
                if (pos > pp[i]) swap(pos, pp[i]), swap(val, bb[i]);
                val ^= bb[i];
            } else {
                bb[i] = val;
                pp[i] = pos;
                return;
            }
        }
    }
    T query(const int &l, const int &r) {
        T res = 0;
        vector<T> &bb = b[r];
        vector<int> &pp = p[r];
        for (int i = sz-1; i >= 0; --i)
            if (pp[i] >= l) res = max(res, res^bb[i]);
        return res;
    }
};

int n, m;
int a[N];
PreSumLB<int> lb;

inline void solve()
{
    cin >> n >> m;
    lb.init();
    for (int i = 1, a; i <= n; ++i) {
        cin >> a;
        lb.append(a);
    }
    int res = 0;
    for (int i = 1, op, x, l, r; i <= m; ++i) {
        cin >> op;
        if (op) {
            cin >> x;
            ++n;
            lb.append(x^res);
        } else {
            cin >> l >> r;
            l = (l^res)%n+1;
            r = (r^res)%n+1;
            if (l > r) swap(l, r);
            res = lb.query(l, r);
            cout << res << endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}