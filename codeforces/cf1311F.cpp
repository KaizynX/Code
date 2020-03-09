#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

int n;
vector<int> des;

template <typename T>
struct BinaryIndexedTree
{
    // set your type
    T tr[N];
    BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
    inline void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
    inline void update(int x, T v) { for ( ; x <= n; x += x&-x) tr[x] += v; }
    inline void update(int x, int y, T v) { update(x, v); update(y+1, -v); }
    inline T query(int x) { T res = 0; for ( ; x; x -= x&-x) res += tr[x]; return res; }
    inline T query(int x, int y) { return query(y)-query(x-1); }
};
BinaryIndexedTree<int> num;
BinaryIndexedTree<long long> sum;

struct Node
{
    int x, v;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.v == n2.v ? n1.x < n2.x : n1.v < n2.v;
    }
} a[N];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].x;
    for (int i = 1; i <= n; ++i) cin >> a[i].v;

    sort(a+1, a+n+1);
    des.resize(n);
    for (int i = 1; i <= n; ++i) des[i-1] = a[i].x;
    sort(des.begin(), des.end());
    des.erase(unique(des.begin(), des.end()), des.end());
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        int p = lower_bound(des.begin(), des.end(), a[i].x)-des.begin()+1;
        #ifdef DEBUG
        cout << p << " " << num.query(p-1) << " " << sum.query(p-1) << endl;
        #endif
        res += 1ll*num.query(p-1)*a[i].x-sum.query(p-1);
        num.update(p, 1);
        sum.update(p, a[i].x);
    }
    cout << res << endl;
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