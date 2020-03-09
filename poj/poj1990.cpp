#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define DEBUG

using namespace std;

const int N = 2e4+7;

struct Node
{
    int v, x;
    bool operator < (const Node &nd) const {
        return v < nd.v;
    }
};

template <typename T>
struct BinaryIndexedTree
{
    int n;
    T tr[N];
    BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
    void init(const int &_n) { n = _n; clear(); }
    void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
    void add(const int &x, const T &v) { for (int i = x ; i <= n; i += i&-i) tr[i] += v; }
    void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
    T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
    T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

int n;
Node a[N];
BinaryIndexedTree<int> numx;
BinaryIndexedTree<long long> sumx;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].v >> a[i].x;
        mx = max(mx, a[i].x);
    }
    numx.init(mx);
    sumx.init(mx);
    sort(a+1, a+n+1);
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        int num_pre = numx.query(a[i].x), num_bac = i-1-num_pre;
        long long sum_pre = sumx.query(a[i].x), sum_bac = sumx.query(mx)-sum_pre;
        res += a[i].v*(num_pre*a[i].x-sum_pre + sum_bac-num_bac*a[i].x);
        numx.add(a[i].x, 1);
        sumx.add(a[i].x, a[i].x);
    }
    cout << res << endl;
    return 0;
}
